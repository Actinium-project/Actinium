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
#include "utiltime.h"
=======
#include <bench/bench.h>
#include <bloom.h>
>>>>>>> upstream/0.16

static void RollingBloom(benchmark::State& state)
{
    CRollingBloomFilter filter(120000, 0.000001);
    std::vector<unsigned char> data(32);
    uint32_t count = 0;
<<<<<<< HEAD
    uint32_t nEntriesPerGeneration = (120000 + 1) / 2;
    uint32_t countnow = 0;
=======
>>>>>>> upstream/0.16
    uint64_t match = 0;
    while (state.KeepRunning()) {
        count++;
        data[0] = count;
        data[1] = count >> 8;
        data[2] = count >> 16;
        data[3] = count >> 24;
<<<<<<< HEAD
        if (countnow == nEntriesPerGeneration) {
            int64_t b = GetTimeMicros();
            filter.insert(data);
            int64_t e = GetTimeMicros();
            std::cout << "RollingBloom-refresh,1," << (e-b)*0.000001 << "," << (e-b)*0.000001 << "," << (e-b)*0.000001 << "\n";
            countnow = 0;
        } else {
            filter.insert(data);
        }
        countnow++;
=======
        filter.insert(data);

>>>>>>> upstream/0.16
        data[0] = count >> 24;
        data[1] = count >> 16;
        data[2] = count >> 8;
        data[3] = count;
        match += filter.contains(data);
    }
}

<<<<<<< HEAD
BENCHMARK(RollingBloom);
=======
BENCHMARK(RollingBloom, 1500 * 1000);
>>>>>>> upstream/0.16
