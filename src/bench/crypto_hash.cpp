<<<<<<< HEAD
// Copyright (c) 2016 The Bitcoin Core developers
=======
// Copyright (c) 2016-2017 The Bitcoin Core developers
>>>>>>> upstream/0.16
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <iostream>

<<<<<<< HEAD
#include "bench.h"
#include "bloom.h"
#include "hash.h"
#include "random.h"
#include "uint256.h"
#include "utiltime.h"
#include "crypto/ripemd160.h"
#include "crypto/sha1.h"
#include "crypto/sha256.h"
#include "crypto/sha512.h"
=======
#include <bench/bench.h>
#include <bloom.h>
#include <hash.h>
#include <random.h>
#include <uint256.h>
#include <utiltime.h>
#include <crypto/ripemd160.h>
#include <crypto/sha1.h>
#include <crypto/sha256.h>
#include <crypto/sha512.h>
>>>>>>> upstream/0.16

/* Number of bytes to hash per iteration */
static const uint64_t BUFFER_SIZE = 1000*1000;

static void RIPEMD160(benchmark::State& state)
{
    uint8_t hash[CRIPEMD160::OUTPUT_SIZE];
    std::vector<uint8_t> in(BUFFER_SIZE,0);
    while (state.KeepRunning())
        CRIPEMD160().Write(in.data(), in.size()).Finalize(hash);
}

static void SHA1(benchmark::State& state)
{
    uint8_t hash[CSHA1::OUTPUT_SIZE];
    std::vector<uint8_t> in(BUFFER_SIZE,0);
    while (state.KeepRunning())
        CSHA1().Write(in.data(), in.size()).Finalize(hash);
}

static void SHA256(benchmark::State& state)
{
    uint8_t hash[CSHA256::OUTPUT_SIZE];
    std::vector<uint8_t> in(BUFFER_SIZE,0);
    while (state.KeepRunning())
        CSHA256().Write(in.data(), in.size()).Finalize(hash);
}

static void SHA256_32b(benchmark::State& state)
{
    std::vector<uint8_t> in(32,0);
    while (state.KeepRunning()) {
<<<<<<< HEAD
        for (int i = 0; i < 1000000; i++) {
            CSHA256().Write(in.data(), in.size()).Finalize(&in[0]);
        }
=======
        CSHA256()
            .Write(in.data(), in.size())
            .Finalize(in.data());
>>>>>>> upstream/0.16
    }
}

static void SHA512(benchmark::State& state)
{
    uint8_t hash[CSHA512::OUTPUT_SIZE];
    std::vector<uint8_t> in(BUFFER_SIZE,0);
    while (state.KeepRunning())
        CSHA512().Write(in.data(), in.size()).Finalize(hash);
}

static void SipHash_32b(benchmark::State& state)
{
    uint256 x;
<<<<<<< HEAD
    while (state.KeepRunning()) {
        for (int i = 0; i < 1000000; i++) {
            *((uint64_t*)x.begin()) = SipHashUint256(0, i, x);
        }
=======
    uint64_t k1 = 0;
    while (state.KeepRunning()) {
        *((uint64_t*)x.begin()) = SipHashUint256(0, ++k1, x);
>>>>>>> upstream/0.16
    }
}

static void FastRandom_32bit(benchmark::State& state)
{
    FastRandomContext rng(true);
    uint32_t x = 0;
    while (state.KeepRunning()) {
<<<<<<< HEAD
        for (int i = 0; i < 1000000; i++) {
            x += rng.rand32();
        }
=======
        x += rng.rand32();
>>>>>>> upstream/0.16
    }
}

static void FastRandom_1bit(benchmark::State& state)
{
    FastRandomContext rng(true);
    uint32_t x = 0;
    while (state.KeepRunning()) {
<<<<<<< HEAD
        for (int i = 0; i < 1000000; i++) {
            x += rng.randbool();
        }
    }
}

BENCHMARK(RIPEMD160);
BENCHMARK(SHA1);
BENCHMARK(SHA256);
BENCHMARK(SHA512);

BENCHMARK(SHA256_32b);
BENCHMARK(SipHash_32b);
BENCHMARK(FastRandom_32bit);
BENCHMARK(FastRandom_1bit);
=======
        x += rng.randbool();
    }
}

BENCHMARK(RIPEMD160, 440);
BENCHMARK(SHA1, 570);
BENCHMARK(SHA256, 340);
BENCHMARK(SHA512, 330);

BENCHMARK(SHA256_32b, 4700 * 1000);
BENCHMARK(SipHash_32b, 40 * 1000 * 1000);
BENCHMARK(FastRandom_32bit, 110 * 1000 * 1000);
BENCHMARK(FastRandom_1bit, 440 * 1000 * 1000);
>>>>>>> upstream/0.16
