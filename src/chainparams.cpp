// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2018 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <chainparams.h>
#include <consensus/merkle.h>

#include <tinyformat.h>
#include <util.h>
#include <utilstrencodings.h>

#include <assert.h>
#include <memory>

#include <chainparamsseeds.h>

static CBlock CreateGenesisBlock(const char* pszTimestamp, const CScript& genesisOutputScript, uint32_t nTime, uint32_t nNonce, uint32_t nBits, int32_t nVersion, const CAmount& genesisReward)
{
    CMutableTransaction txNew;
    txNew.nVersion = 1;
    txNew.vin.resize(1);
    txNew.vout.resize(1);
    txNew.vin[0].scriptSig = CScript() << 486604799 << CScriptNum(4) << std::vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
    txNew.vout[0].nValue = genesisReward;
    txNew.vout[0].scriptPubKey = genesisOutputScript;

    CBlock genesis;
    genesis.nTime    = nTime;
    genesis.nBits    = nBits;
    genesis.nNonce   = nNonce;
    genesis.nVersion = nVersion;
    genesis.vtx.push_back(MakeTransactionRef(std::move(txNew)));
    genesis.hashPrevBlock.SetNull();
    genesis.hashMerkleRoot = BlockMerkleRoot(genesis);
    return genesis;
}

/**
 * Build the genesis block. Note that the output of its generation
 * transaction cannot be spent since it did not originally exist in the
 * database.
 *
 * CBlock(hash=000000000019d6, ver=1, hashPrevBlock=00000000000000, hashMerkleRoot=4a5e1e, nTime=1231006505, nBits=1d00ffff, nNonce=2083236893, vtx=1)
 *   CTransaction(hash=4a5e1e, ver=1, vin.size=1, vout.size=1, nLockTime=0)
 *     CTxIn(COutPoint(000000, -1), coinbase 04ffff001d0104455468652054696d65732030332f4a616e2f32303039204368616e63656c6c6f72206f6e206272696e6b206f66207365636f6e64206261696c6f757420666f722062616e6b73)
 *     CTxOut(nValue=50.00000000, scriptPubKey=0x5F1DF16B2B704C8A578D0B)
 *   vMerkleTree: 4a5e1e
 */
static CBlock CreateGenesisBlock(uint32_t nTime, uint32_t nNonce, uint32_t nBits, int32_t nVersion, const CAmount& genesisReward)
{
    const char* pszTimestamp = "NY Times 24/Apr/2018 Toronto Van Attack Suspect Expressed Anger at Women";
    const CScript genesisOutputScript = CScript() << ParseHex("04678afdb0fe5548271967f1a67130b7105cd6a828e03909a67962e0ea1f61deb649f6bc3f4cef38c4f35504e51ec112de5c384df7ba0b8d578a4c702b6bf11d5f") << OP_CHECKSIG;
    return CreateGenesisBlock(pszTimestamp, genesisOutputScript, nTime, nNonce, nBits, nVersion, genesisReward);
}

void CChainParams::UpdateVersionBitsParameters(Consensus::DeploymentPos d, int64_t nStartTime, int64_t nTimeout)
{
    consensus.vDeployments[d].nStartTime = nStartTime;
    consensus.vDeployments[d].nTimeout = nTimeout;
}

/**
 * Main network
 */
/**
 * What makes a good checkpoint block?
 * + Is surrounded by blocks with reasonable timestamps
 *   (no blocks before with a timestamp after, none after with
 *    timestamp before)
 * + Contains no strange transactions
 */

class CMainParams : public CChainParams {
public:
    CMainParams() {
        strNetworkID = "main";
        consensus.nSubsidyHalvingInterval = 840000;
        consensus.BIP34Height = 1000;
        consensus.BIP34Hash = uint256S("f1d584601e77187e22daa8d551d8307295474a49a54055a0e3feb182223da7ee");
        consensus.BIP65Height = 1000;
        consensus.BIP66Height = 1000;
        consensus.GPUSupportHeight = 55000;
        consensus.ACMZawyLWMAHeight = 85000;
        consensus.powLimit = uint256S("00000fffffffffffffffffffffffffffffffffffffffffffffffffffffffffff");
        consensus.nPowTargetTimespan = 3.5 * 24 * 60 * 60; // 3.5 days
        consensus.nPowTargetSpacing = 2.5 * 60;
        consensus.fPowAllowMinDifficultyBlocks = false;
        consensus.fPowNoRetargeting = false;
        consensus.nRuleChangeActivationThreshold = 6048; // 75% of 8064
        consensus.nMinerConfirmationWindow = 8064; // nPowTargetTimespan / nPowTargetSpacing * 4
        consensus.nZawyLwmaAveragingWindow = 60;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].bit = 28;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nStartTime = 1199145601; // January 1, 2008
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nTimeout = 1230767999; // December 31, 2008

        // Deployment of BIP68, BIP112, and BIP113.
        consensus.vDeployments[Consensus::DEPLOYMENT_CSV].bit = 0;
        consensus.vDeployments[Consensus::DEPLOYMENT_CSV].nStartTime = 0;
        consensus.vDeployments[Consensus::DEPLOYMENT_CSV].nTimeout = Consensus::BIP9Deployment::NO_TIMEOUT;

        // Deployment of SegWit (BIP141, BIP143, and BIP147)
        consensus.vDeployments[Consensus::DEPLOYMENT_SEGWIT].bit = 1;
        consensus.vDeployments[Consensus::DEPLOYMENT_SEGWIT].nStartTime = 0;
        consensus.vDeployments[Consensus::DEPLOYMENT_SEGWIT].nTimeout = Consensus::BIP9Deployment::NO_TIMEOUT;

        // The best chain should have at least this much work.
        consensus.nMinimumChainWork = uint256S("0x0000000000000000000000000000000000000000000000000b36a5d7724fc9a4");

        // By default assume that the signatures in ancestors of this block are valid.
        consensus.defaultAssumeValid = uint256S("0xa9981048eaac207ec6ae84afd3e29d1f4e8c602269564b468ec9bde97b569925"); //block 123800

        /**
         * The message start string is designed to be unlikely to occur in normal data.
         * The characters are rarely used upper ASCII, not valid as UTF-8, and produce
         * a large 32-bit integer with any alignment.
         */
        pchMessageStart[0] = 0xfa;
        pchMessageStart[1] = 0xc1;
        pchMessageStart[2] = 0xb7;
        pchMessageStart[3] = 0xd7;
        nDefaultPort = 4334;
        nPruneAfterHeight = 100000;

        genesis = CreateGenesisBlock(1524649713, 743522, 0x1e0ffff0, 1, 50 * COIN);
        consensus.hashGenesisBlock = genesis.GetHash();
        assert(consensus.hashGenesisBlock == uint256S("0x28d77872e23714562f49a1be792c276623c1bbe3fdcf21b6035cfde78b00b824"));
        assert(genesis.hashMerkleRoot == uint256S("0xec55b10e2f22adf88cb40df86df4d912687c13e6a4d6289513883adaef2c9191"));

        // Note that of those with the service bits flag, most only support a subset of possible options

        vSeeds.emplace_back("seeder1.shit.supply");
        vSeeds.emplace_back("seeder2.shit.supply");
        vSeeds.emplace_back("seeder3.shit.supply");
        vSeeds.emplace_back("seeder4.shit.supply");

        base58Prefixes[PUBKEY_ADDRESS]  = std::vector<unsigned char>(1,53);  // N
        base58Prefixes[SCRIPT_ADDRESS]  = std::vector<unsigned char>(1,5);   // 3
        base58Prefixes[SCRIPT_ADDRESS2] = std::vector<unsigned char>(1,55);  // P
        base58Prefixes[SECRET_KEY]      = std::vector<unsigned char>(1,181); // 7 or T
        base58Prefixes[EXT_PUBLIC_KEY]  = {0x04, 0x88, 0xB2, 0x1E};
        base58Prefixes[EXT_SECRET_KEY]  = {0x04, 0x88, 0xAD, 0xE4};

        bech32_hrp = "acm";

        vFixedSeeds = std::vector<SeedSpec6>(pnSeed6_main, pnSeed6_main + ARRAYLEN(pnSeed6_main));

        fDefaultConsistencyChecks = false;
        fRequireStandard = true;
        fMineBlocksOnDemand = false;

        checkpointData = (CCheckpointData){
            {
                {0,     uint256S("0x28d77872e23714562f49a1be792c276623c1bbe3fdcf21b6035cfde78b00b824")},
                {100,   uint256S("0xcc732316268fe403d692b4ba04b48c866c357a86d560473ef2a1cea176eea396")},
                {150,   uint256S("0xebc507a4e91a6947847a99d46c6765db03679f1e911c5c0236f59f30d62d0fd9")},
                {300,   uint256S("0xf21218cf0f39cbf23113fe7962860b08292b2c59d6f577b85af5a8280e487289")},
                {600,   uint256S("0x6cb9d69493db2deac182c8dcd56fd01a44f5e775365f09bd973a427cf729d491")},
                {900,   uint256S("0x415b1c86d6fef15af7a51dbb5aca8e204ac60454480c1d53b1d14eb034cef0a7")},
                {1000,  uint256S("0xf1d584601e77187e22daa8d551d8307295474a49a54055a0e3feb182223da7ee")},
                {1100,  uint256S("0x2fa9d2cb200e033de86488a8b81d8009112f60614a06c803080cf167e99faf90")},
                {1350,  uint256S("0x90879af3c77512419bf6d3bda0030a0c778e01cac37d5fc3ebbf021b659eb56c")},
                {8918,  uint256S("0xf73dbfc07ee8275e43d57eb2ca5efb8dd721db8ced5d490502fd8330791957e0")},
                {15313, uint256S("0x944690e2499d10b2fad85abe40bd8d96a8e39e4cfc0cf9dd767e4745502d53e8")},
                {20554, uint256S("0x2302ebfe233144e3c2453e5b7dbfe1d82ddfed7765e15e29c31585f76fb679a5")},
                {25000, uint256S("0x910672dd97f309b2b9e31cc1d90c76f0ac3471d28d984c6de2248e90a47e98a4")},
                {30000, uint256S("0xcc690003d9b0106669639e0599e2f36afd196081f341d5c9182f6d89ab6d33c8")},
                {35060, uint256S("0xfaa21ea9167dd878dd3789a68455ef035877edcdb96ea15133693ef75de6f4a6")},
                {42384, uint256S("0x26f08f68ff269ae5f98fdb5e484bd9cefabdfd8f01291858909c0f57b1b2ec27")},
                {43545, uint256S("0xb4e80c89a411a67b3598891cbe132f6518c5c7a7a47971ba6e35939644a403f3")},
                {43700, uint256S("0x11cf0da27f67c1cb0d81b28d238dd28ee1c06d6e5e7c7a96cc1727b9d634d814")},
                {79769, uint256S("0x45c689944af98e91071ec5429778b8716b802f9c6632704d29abe34b2f8cc0ae")},
                {90690, uint256S("0xb9270df40c471556893a5a6538c20119f03ddf55ec394dd322e4a204be22d7fb")},
                {123800, uint256S("0xa9981048eaac207ec6ae84afd3e29d1f4e8c602269564b468ec9bde97b569925")}
            }};

        // Data as of block 3f6243a04732bd9bc8b2a5af87dfe528d3fcfa457d1078bb44a4b9320f98b363 (height 1300).
        chainTxData = ChainTxData{
            1524812789, // * UNIX timestamp of last known number of transactions
            1797,       // * total number of transactions between genesis and that timestamp
                        //   (the tx=... number in the SetBestChain debug.log lines)
            0.01        // * estimated number of transactions per second after that timestamp
        };

        /* disable fallback fee on mainnet */
        m_fallback_fee_enabled = false;
    }
};

/**
 * Testnet (v3)
 */
class CTestNetParams : public CChainParams {
public:
    CTestNetParams() {
        strNetworkID = "test";
        consensus.nSubsidyHalvingInterval = 840000;
        consensus.BIP34Height = 0;
        consensus.BIP34Hash = uint256S("7c617cc84dc2bff1497836216d6b850cc4e871359ab1afc2d19ef099f9f81f1b");
        consensus.BIP65Height = 0;
        consensus.BIP66Height = 0;
        consensus.GPUSupportHeight = 2;
        consensus.ACMZawyLWMAHeight = 55;
        consensus.powLimit = uint256S("00000fffffffffffffffffffffffffffffffffffffffffffffffffffffffffff");
        consensus.nPowTargetTimespan = 3.5 * 24 * 60 * 60; // 3.5 days
        consensus.nPowTargetSpacing = 2.5 * 60;
        consensus.fPowAllowMinDifficultyBlocks = true;
        consensus.fPowNoRetargeting = false;
        consensus.nRuleChangeActivationThreshold = 1512; // 75% for testchains
        consensus.nMinerConfirmationWindow = 2016; // nPowTargetTimespan / nPowTargetSpacing
        consensus.nZawyLwmaAveragingWindow = 60;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].bit = 28;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nStartTime = 1199145601; // January 1, 2008
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nTimeout = 1230767999; // December 31, 2008

        // Deployment of BIP68, BIP112, and BIP113.
        consensus.vDeployments[Consensus::DEPLOYMENT_CSV].bit = 0;
        consensus.vDeployments[Consensus::DEPLOYMENT_CSV].nStartTime = Consensus::BIP9Deployment::ALWAYS_ACTIVE;
        consensus.vDeployments[Consensus::DEPLOYMENT_CSV].nTimeout = Consensus::BIP9Deployment::NO_TIMEOUT;

        // Deployment of SegWit (BIP141, BIP143, and BIP147)
        consensus.vDeployments[Consensus::DEPLOYMENT_SEGWIT].bit = 1;
        consensus.vDeployments[Consensus::DEPLOYMENT_SEGWIT].nStartTime = Consensus::BIP9Deployment::ALWAYS_ACTIVE;
        consensus.vDeployments[Consensus::DEPLOYMENT_SEGWIT].nTimeout = Consensus::BIP9Deployment::NO_TIMEOUT;

        // The best chain should have at least this much work.
        consensus.nMinimumChainWork = uint256S("0x00");

        // By default assume that the signatures in ancestors of this block are valid.
        consensus.defaultAssumeValid = uint256S("0x00");

        pchMessageStart[0] = 0xfa;
        pchMessageStart[1] = 0xd2;
        pchMessageStart[2] = 0xc7;
        pchMessageStart[3] = 0xf7;
        nDefaultPort = 4335;
        nPruneAfterHeight = 1000;

        genesis = CreateGenesisBlock(1524650001, 19905, 0x1e0ffff0, 1, 50 * COIN);
        consensus.hashGenesisBlock = genesis.GetHash();
        assert(consensus.hashGenesisBlock == uint256S("0x7c617cc84dc2bff1497836216d6b850cc4e871359ab1afc2d19ef099f9f81f1b"));
        assert(genesis.hashMerkleRoot == uint256S("0xec55b10e2f22adf88cb40df86df4d912687c13e6a4d6289513883adaef2c9191"));

        vFixedSeeds.clear();
        vSeeds.clear();
        // nodes with support for servicebits filtering should be at the top
        //vSeeds.emplace_back("testnet-seed.actinium.org", true);

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 43);  // J
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 196); // 2
        base58Prefixes[SCRIPT_ADDRESS2] = std::vector<unsigned char>(1, 58); // Q
        base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 171);     //
        base58Prefixes[EXT_PUBLIC_KEY] = {0x04, 0x35, 0x87, 0xCF};
        base58Prefixes[EXT_SECRET_KEY] = {0x04, 0x35, 0x83, 0x94};

        bech32_hrp = "tacm";

        vFixedSeeds = std::vector<SeedSpec6>(pnSeed6_test, pnSeed6_test + ARRAYLEN(pnSeed6_test));

        fDefaultConsistencyChecks = false;
        fRequireStandard = false;
        fMineBlocksOnDemand = false;

        checkpointData = (CCheckpointData) {
            {
                {0, uint256S("0x7c617cc84dc2bff1497836216d6b850cc4e871359ab1afc2d19ef099f9f81f1b") },
            }
        };

        chainTxData = ChainTxData{
            0,
            0,
            0
        };

        /* enable fallback fee on testnet */
        m_fallback_fee_enabled = true;
    }
};

/**
 * Regression test
 */
class CRegTestParams : public CChainParams {
public:
    CRegTestParams() {
        strNetworkID = "regtest";
        consensus.nSubsidyHalvingInterval = 150;
        consensus.BIP16Height = 0; // always enforce P2SH BIP16 on regtest
        consensus.BIP34Height = 100000000; // BIP34 has not activated on regtest (far in the future so block v1 are not rejected in tests)
        consensus.BIP34Hash = uint256();
        consensus.BIP65Height = 1351; // BIP65 activated on regtest (Used in rpc activation tests)
        consensus.BIP66Height = 1251; // BIP66 activated on regtest (Used in rpc activation tests)
        consensus.GPUSupportHeight = 3;
        consensus.ACMZawyLWMAHeight = 6;
        consensus.powLimit = uint256S("7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff");
        consensus.nPowTargetTimespan = 3.5 * 24 * 60 * 60; // two weeks
        consensus.nPowTargetSpacing = 2.5 * 60;
        consensus.fPowAllowMinDifficultyBlocks = true;
        consensus.fPowNoRetargeting = true;
        consensus.nRuleChangeActivationThreshold = 108; // 75% for testchains
        consensus.nMinerConfirmationWindow = 144; // Faster than normal for regtest (144 instead of 2016)
        consensus.nZawyLwmaAveragingWindow = 60;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].bit = 28;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nStartTime = 0;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nTimeout = 999999999999ULL;
        consensus.vDeployments[Consensus::DEPLOYMENT_CSV].bit = 0;
        consensus.vDeployments[Consensus::DEPLOYMENT_CSV].nStartTime = Consensus::BIP9Deployment::ALWAYS_ACTIVE;
        consensus.vDeployments[Consensus::DEPLOYMENT_CSV].nTimeout = Consensus::BIP9Deployment::NO_TIMEOUT;
        consensus.vDeployments[Consensus::DEPLOYMENT_SEGWIT].bit = 1;
        consensus.vDeployments[Consensus::DEPLOYMENT_SEGWIT].nStartTime = Consensus::BIP9Deployment::ALWAYS_ACTIVE;
        consensus.vDeployments[Consensus::DEPLOYMENT_SEGWIT].nTimeout = Consensus::BIP9Deployment::NO_TIMEOUT;


        // The best chain should have at least this much work.
        consensus.nMinimumChainWork = uint256S("0x00");

        // By default assume that the signatures in ancestors of this block are valid.
        consensus.defaultAssumeValid = uint256S("0x00");

        pchMessageStart[0] = 0xfa;
        pchMessageStart[1] = 0xb3;
        pchMessageStart[2] = 0xb7;
        pchMessageStart[3] = 0xd7;
        nDefaultPort = 14444;
        nPruneAfterHeight = 1000;

        genesis = CreateGenesisBlock(1524650028, 771587, 0x1e0ffff0, 1, 50 * COIN);
        consensus.hashGenesisBlock = genesis.GetHash();
        assert(consensus.hashGenesisBlock == uint256S("0xf05cd14f31c18d661efb3dc152ddbdf0da1305c73beac0a9e348013c3b3f8ad2"));
        assert(genesis.hashMerkleRoot == uint256S("0xec55b10e2f22adf88cb40df86df4d912687c13e6a4d6289513883adaef2c9191"));

        vFixedSeeds.clear(); //!< Regtest mode doesn't have any fixed seeds.
        vSeeds.clear();      //!< Regtest mode doesn't have any DNS seeds.

        fDefaultConsistencyChecks = true;
        fRequireStandard = false;
        fMineBlocksOnDemand = true; 

        checkpointData = (CCheckpointData) {
            {
                {0, uint256S("0xf05cd14f31c18d661efb3dc152ddbdf0da1305c73beac0a9e348013c3b3f8ad2") },
            }
        };

        chainTxData = ChainTxData{
            0,
            0,
            0
        };

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 40);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 193);
        base58Prefixes[SCRIPT_ADDRESS2] = std::vector<unsigned char>(1, 42);
        base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 168);
        base58Prefixes[EXT_PUBLIC_KEY] = {0x04, 0x35, 0x87, 0xCF};
        base58Prefixes[EXT_SECRET_KEY] = {0x04, 0x35, 0x83, 0x94};

        bech32_hrp = "racm";
    }
};

static std::unique_ptr<CChainParams> globalChainParams;

const CChainParams &Params() {
    assert(globalChainParams);
    return *globalChainParams;
}

std::unique_ptr<CChainParams> CreateChainParams(const std::string& chain)
{
    if (chain == CBaseChainParams::MAIN)
        return std::unique_ptr<CChainParams>(new CMainParams());
    else if (chain == CBaseChainParams::TESTNET)
        return std::unique_ptr<CChainParams>(new CTestNetParams());
    else if (chain == CBaseChainParams::REGTEST)
        return std::unique_ptr<CChainParams>(new CRegTestParams());
    throw std::runtime_error(strprintf("%s: Unknown chain %s.", __func__, chain));
}

void SelectParams(const std::string& network)
{
    SelectBaseParams(network);
    globalChainParams = CreateChainParams(network);
}

void UpdateVersionBitsParameters(Consensus::DeploymentPos d, int64_t nStartTime, int64_t nTimeout)
{
    globalChainParams->UpdateVersionBitsParameters(d, nStartTime, nTimeout);
}
