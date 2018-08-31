Actinium Core version *0.18.0* is now available from:

  <https://download.Actinium.org/Actinium-0.18.0/>

This is a new minor version release, including various bugfixes and
performance improvements, as well as updated translations.

Please report bugs using the issue tracker at GitHub:

  <https://github.com/Actinium-project/Actinium/issues>

To receive security and update notifications, please subscribe to:

  <https://groups.google.com/forum/#!forum/Actinium-dev>

How to Upgrade
==============

If you are running an older version, shut it down. Wait until it has completely
shut down (which might take a few minutes for older versions), then run the 
installer (on Windows) or just copy over `/Applications/Actinium-Qt` (on Mac)
or `Actiniumd`/`Actinium-qt` (on Linux).

The first time you run version 0.15.0 or higher, your chainstate database will
be converted to a new format, which will take anywhere from a few minutes to
half an hour, depending on the speed of your machine.

The file format of `fee_estimates.dat` changed in version 0.15.0. Hence, a
downgrade from version 0.15 or upgrade to version 0.15 will cause all fee
estimates to be discarded.

Note that the block database format also changed in version 0.8.0 and there is no
automatic upgrade code from before version 0.8 to version 0.15.0. Upgrading
directly from 0.7.x and earlier without redownloading the blockchain is not supported.
However, as usual, old wallet versions are still supported.

Downgrading warning
-------------------

The chainstate database for this release is not compatible with previous
releases, so if you run 0.15 and then decide to switch back to any
older version, you will need to run the old release with the `-reindex-chainstate`
option to rebuild the chainstate data structures in the old format.

If your node has pruning enabled, this will entail re-downloading and
processing the entire blockchain.

Compatibility
==============

Actinium Core is extensively tested on multiple operating systems using
the Linux kernel, macOS 10.8+, and Windows Vista and later. Windows XP is not supported.

Actinium Core should also work on most other Unix-like systems but is not
frequently tested on them.


### New `rescanblockchain` RPC

A new RPC `rescanblockchain` has been added to manually invoke a blockchain rescan.
The RPC supports start and end-height arguments for the rescan, and can be used in a
multiwallet environment to rescan the blockchain at runtime.

### New `savemempool` RPC
A new `savemempool` RPC has been added which allows the current mempool to be saved to
disk at any time to avoid it being lost due to crashes / power loss.

### Safe mode disabled by default

Safe mode is now disabled by default and must be manually enabled (with `-disablesafemode=0`) if you wish to use it. Safe mode is a feature that disables a subset of RPC calls - mostly related to the wallet and sending - automatically in case certain problem conditions with the network are detected. However, developers have come to regard these checks as not reliable enough to act on automatically. Even with safe mode disabled, they will still cause warnings in the `warnings` field of the `getneworkinfo` RPC and launch the `-alertnotify` command.

### Renamed script for creating JSON-RPC credentials

The `share/rpcuser/rpcuser.py` script was renamed to `share/rpcauth/rpcauth.py`. This script can be
used to create `rpcauth` credentials for a JSON-RPC user.

### Validateaddress improvements

The `validateaddress` RPC output has been extended with a few new fields, and support for segwit addresses (both P2SH and Bech32). Specifically:
* A new field `iswitness` is True for P2WPKH and P2WSH addresses ("ltc1..." addresses), but not for P2SH-wrapped segwit addresses (see below).
* The existing field `isscript` will now also report True for P2WSH addresses.
* A new field `embedded` is present for all script addresses where the script is known and matches something that can be interpreted as a known address. This is particularly true for P2SH-P2WPKH and P2SH-P2WSH addresses. The value for `embedded` includes much of the information `validateaddress` would report if invoked directly on the embedded address.
* For multisig scripts a new `pubkeys` field was added that reports the full public keys involved in the script (if known). This is a replacement for the existing `addresses` field (which reports the same information but encoded as P2PKH addresses), represented in a more useful and less confusing way. The `addresses` field remains present for non-segwit addresses for backward compatibility.
* For all single-key addresses with known key (even when wrapped in P2SH or P2WSH), the `pubkey` field will be present. In particular, this means that invoking `validateaddress` on the output of `getnewaddress` will always report the `pubkey`, even when the address type is P2SH-P2WPKH.

### Low-level changes

- The deprecated RPC `getinfo` was removed. It is recommended that the more specific RPCs are used:
  * `getblockchaininfo`
  * `getnetworkinfo`
  * `getwalletinfo`
  * `getmininginfo`
- The wallet RPC `getreceivedbyaddress` will return an error if called with an address not in the wallet.
- The wallet RPC `addwitnessaddress` was deprecated and will be removed in version 0.17,
  set the `address_type` argument of `getnewaddress`, or option `-addresstype=[bech32|p2sh-segwit]` instead.
- `dumpwallet` now includes hex-encoded scripts from the wallet in the dumpfile, and
  `importwallet` now imports these scripts, but corresponding addresses may not be added
  correctly or a manual rescan may be required to find relevant transactions.
- The RPC `getblockchaininfo` now includes an `errors` field.
- A new `blockhash` parameter has been added to the `getrawtransaction` RPC which allows for a raw transaction to be fetched from a specific block if known, even without `-txindex` enabled.
- The `decoderawtransaction` and `fundrawtransaction` RPCs now have optional `iswitness` parameters to override the
  heuristic witness checks if necessary.
- The `walletpassphrase` timeout is now clamped to 2^30 seconds.
- Using addresses with the `createmultisig` RPC is now deprecated, and will be removed in a later version. Public keys should be used instead.
- Blockchain rescans now no longer lock the wallet for the entire rescan process, so other RPCs can now be used at the same time (although results of balances / transactions may be incorrect or incomplete until the rescan is complete).
- The `logging` RPC has now been made public rather than hidden.
- An `initialblockdownload` boolean has been added to the `getblockchaininfo` RPC to indicate whether the node is currently in IBD or not.
- `minrelaytxfee` is now included in the output of `getmempoolinfo`

Other changed command-line options
----------------------------------
- `-debuglogfile=<file>` can be used to specify an alternative debug logging file.
- Actinium-cli now has an `-stdinrpcpass` option to allow the RPC password to be read from standard input.
- The `-usehd` option has been removed.
- Actinium-cli now supports a new `-getinfo` flag which returns an output like that of the now-removed `getinfo` RPC.

Testing changes
----------------
- The default regtest JSON-RPC port has been changed to 19443 to avoid conflict with testnet's default of 19332.
- Segwit is now always active in regtest mode by default. Thus, if you upgrade a regtest node you will need to either -reindex or use the old rules by adding `vbparams=segwit:0:999999999999` to your regtest Actinium.conf. Failure to do this will result in a CheckBlockIndex() assertion failure that will look like: Assertion `(pindexFirstNeverProcessed != nullptr) == (pindex->nChainTx == 0)' failed.

0.16.0 change log
------------------

### Block and transaction handling
- #13199 `c71e535` Bugfix: ensure consistency of m_failed_blocks after reconsiderblock (sdaftuar)
- #13023 `bb79aaf` Fix some concurrency issues in ActivateBestChain() (skeees)

### P2P protocol and network code
- #12626 `f60e84d` Limit the number of IPs addrman learns from each DNS seeder (EthanHeilman)

### Wallet
- #13265 `5d8de76` Exit SyncMetaData if there are no transactions to sync (laanwj)
- #13030 `5ff571e` Fix zapwallettxes/multiwallet interaction. (jnewbery)
- #13622 `c04a4a5` Remove mapRequest tracking that just effects Qt display. (TheBlueMatt)
- #12905 `cfc6f74` [rpcwallet] Clamp walletpassphrase value at 100M seconds (sdaftuar)
- #13437 `ed82e71` wallet: Erase wtxOrderd wtx pointer on removeprunedfunds (MarcoFalke)

### RPC and other APIs
- #13451 `cbd2f70` rpc: expose CBlockIndex::nTx in getblock(header) (instagibbs)
- #13507 `f7401c8` RPC: Fix parameter count check for importpubkey (kristapsk)
- #13452 `6b9dc8c` rpc: have verifytxoutproof check the number of txns in proof structure (instagibbs)
- #12837 `bf1f150` rpc: fix type mistmatch in `listreceivedbyaddress` (joemphilips)
- #12743 `657dfc5` Fix csBestBlock/cvBlockChange waiting in rpc/mining (sipa)

### GUI
- #12999 `1720eb3` Show the Window when double clicking the taskbar icon (ken2812221)
- #12650 `f118a7a` Fix issue: "default port not shown correctly in settings dialog" (251Labs)
- #13251 `ea487f9` Rephrase Bech32 checkbox texts, and enable it with legacy address default (fanquake)
- #12432 `f78e7f6` [qt] send: Clear All also resets coin control options (Sjors)
- #12617 `21dd512` gui: Show messages as text not html (laanwj)
- #12793 `cf6feb7` qt: Avoid reseting on resetguisettigs=0 (MarcoFalke)

### Build system
- #12474 `b0f692f` Allow depends system to support armv7l (hkjn)
- #12585 `72a3290` depends: Switch to downloading expat from GitHub (fanquake)
- #12648 `46ca8f3` test: Update trusted git root (MarcoFalke)
- #11995 `686cb86` depends: Fix Qt build with Xcode 9 (fanquake)
- #12636 `845838c` backport: #11995 Fix Qt build with Xcode 9 (fanquake)
- #12946 `e055bc0` depends: Fix Qt build with XCode 9.3 (fanquake)
- #12998 `7847b92` Default to defining endian-conversion DECLs in compat w/o config (TheBlueMatt)
- #13544 `9fd3e00` depends: Update Qt download url (fanquake)
- #12573 `88d1a64` Fix compilation when compiler do not support `__builtin_clz*` (532479301)

### Tests and QA
- #12447 `01f931b` Add missing signal.h header (laanwj)
- #12545 `1286f3e` Use wait_until to ensure ping goes out (Empact)
- #12804 `4bdb0ce` Fix intermittent rpc_net.py failure. (jnewbery)
- #12553 `0e98f96` Prefer wait_until over polling with time.sleep (Empact)
- #12486 `cfebd40` Round target fee to 8 decimals in assert_fee_amount (kallewoof)
- #12843 `df38b13` Test starting bitcoind with -h and -version (jnewbery)
- #12475 `41c29f6` Fix python TypeError in script.py (MarcoFalke)
- #12638 `0a76ed2` Cache only chain and wallet for regtest datadir (MarcoFalke)
- #12902 `7460945` Handle potential cookie race when starting node (sdaftuar)
- #12904 `6c26df0` Ensure bitcoind processes are cleaned up when tests end (sdaftuar)
- #13049 `9ea62a3` Backports (MarcoFalke)
- #13201 `b8aacd6` Handle disconnect_node race (sdaftuar)
- #13061 `170b309` Make tests pass after 2020 (bmwiedemann)
- #13192 `79c4fff` [tests] Fixed intermittent failure in `p2p_sendheaders.py` (lmanners)
- #13300 `d9c5630` qa: Initialize lockstack to prevent null pointer deref (MarcoFalke)
- #13545 `e15e3a9` tests: Fix test case `streams_serializedata_xor` Remove Boost dependency. (practicalswift)
- #13304 `cbdabef` qa: Fix `wallet_listreceivedby` race (MarcoFalke)
- #13852 `b64f02f` Make signrawtransaction give an error when amount is needed but missing (ajtowns)
- #13797 `6518bcd` bitcoinconsensus: invalid flags should be set to bitcoinconsensus_error type, add test cases covering bitcoinconsensus error codes (Thomas Kerin)

### Miscellaneous
- #11246 `777519b` github-merge: Coalesce git fetches (laanwj)
- #10871 `c9a4aa8` Handle getinfo in bitcoin-cli w/ -getinfo (revival of #8843) (achow101)
- #11419 `093074b` Utils: Fix launchctl not being able to stop bitcoind (OmeGak)
- #11394 `6e4e98e` Perform a weaker subtree check in Travis (sipa)
- #11702 `4122112` [build] Add a script for installing db4 (jamesob)
- #11794 `dd49862` Prefix leveldb debug logging (laanwj)
- #11781 `24df9af` Add `-debuglogfile` option (laanwj)
- #10773 `c17f11f` Shell script cleanups (practicalswift)
- #11829 `7630a1f` Test datadir specified in conf file exists (MeshCollider)
- #11836 `d44535d` Rename rpcuser.py to rpcauth.py (hkjn)
- #11831 `d48ab83` Always return true if AppInitMain got to the end (TheBlueMatt)
- #11943 `1808660` contrib: fix typo in install_db4.sh help message (laanwj)
- #12075 `c991b30` [scripts] Add missing univalue file to copyright_header.py (fanquake)
- #12197 `000ac4f` Log debug build status and warn when running benchmarks (laanwj)
- #10672 `6ab0e4c` Avoid division by zero in the case of a corrupt estimates file (practicalswift)
- #11273 `cdd6bbf` Ignore old format estimation file (Xekyo)
- #11951 `1fb34e0` Remove dead feeest-file read code for old versions (TheBlueMatt)
- #11421 `9ccafb1` Merge current secp256k1 subtree (MarcoFalke)
- #11573 `2631d55` [Util] Update tinyformat.h (fanquake)
- #10529 `331352f` Improve bitcoind systemd service file (Flowdalic)
- #11620 `70fec9e` [build] .gitignore: add background.tiff (Sjors)
- #11558 `68e021e` Minimal code changes to allow msvc compilation (sipsorcery)
- #11284 `10bee0d` Fix invalid memory access in CScript::operator+= (guidovranken, ajtowns)
- #10939 `a1f7f18` [init] Check non-emptiness of -blocknotify command prior to executing (practicalswift)
- #11467 `937613d` Fix typos. Use nullptr instead of NULL (practicalswift)
- #11834 `5bea05b` [verify-commits] Fix gpg.sh's echoing for commits with '\n' (TheBlueMatt)
- #11830 `a13e443` rpcuser.py: Use 'python' not 'python2' (hkjn)
- #12194 `7abb0f0` Add change type option to fundrawtransaction (promag)
- #12269 `2ae7cf8` Update defaultAssumeValid to block 506067 (gmaxwell)
- #11952 `9ab9963` univalue: Bump subtree (MarcoFalke)
- #12367 `09fc859` Fix two fast-shutdown bugs (TheBlueMatt)
- #12422 `4d54e7a` util: Make LockDirectory thread-safe, consistent, and fix OpenBSD 6.2 build (laanwj)
- #482 `5c8e26d` Actinium: Basic changes for v0.16 release (thrasher-)

Credits
=======

Thanks to everyone who directly contributed to this release:

- [The Bitcoin Core Developers](/doc/release-notes)
- Adrian Gallagher
- aunyks
- coblee
- gabrieldov
- Martin Smith 
- ppm0
- romanornr
- shaolinfry
- spl0i7
- stedwms
- ultragtx
- VKoskiv
- voidmain
- wbsmolen
- xinxi

And to those that reported security issues:

- Braydon Fuller
- Himanshu Mehta