<<<<<<< HEAD
// Copyright (c) 2015-2016 The Bitcoin Core developers
=======
// Copyright (c) 2015-2017 The Bitcoin Core developers
>>>>>>> upstream/0.16
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_BENCH_BENCH_H
#define BITCOIN_BENCH_BENCH_H

#include <functional>
#include <limits>
#include <map>
#include <string>
<<<<<<< HEAD
=======
#include <vector>
#include <chrono>
>>>>>>> upstream/0.16

#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/stringize.hpp>

// Simple micro-benchmarking framework; API mostly matches a subset of the Google Benchmark
// framework (see https://github.com/google/benchmark)
// Why not use the Google Benchmark framework? Because adding Yet Another Dependency
// (that uses cmake as its build system and has lots of features we don't need) isn't
// worth it.

/*
 * Usage:

static void CODE_TO_TIME(benchmark::State& state)
{
    ... do any setup needed...
    while (state.KeepRunning()) {
       ... do stuff you want to time...
    }
    ... do any cleanup needed...
}

<<<<<<< HEAD
BENCHMARK(CODE_TO_TIME);

 */
 
namespace benchmark {

    class State {
        std::string name;
        double maxElapsed;
        double beginTime;
        double lastTime, minTime, maxTime, countMaskInv;
        uint64_t count;
        uint64_t countMask;
        uint64_t beginCycles;
        uint64_t lastCycles;
        uint64_t minCycles;
        uint64_t maxCycles;
    public:
        State(std::string _name, double _maxElapsed) : name(_name), maxElapsed(_maxElapsed), count(0) {
            minTime = std::numeric_limits<double>::max();
            maxTime = std::numeric_limits<double>::min();
            minCycles = std::numeric_limits<uint64_t>::max();
            maxCycles = std::numeric_limits<uint64_t>::min();
            countMask = 1;
            countMaskInv = 1./(countMask + 1);
        }
        bool KeepRunning();
    };

    typedef std::function<void(State&)> BenchFunction;

    class BenchRunner
    {
        typedef std::map<std::string, BenchFunction> BenchmarkMap;
        static BenchmarkMap &benchmarks();

    public:
        BenchRunner(std::string name, BenchFunction func);

        static void RunAll(double elapsedTimeForOne=1.0);
    };
}

// BENCHMARK(foo) expands to:  benchmark::BenchRunner bench_11foo("foo", foo);
#define BENCHMARK(n) \
    benchmark::BenchRunner BOOST_PP_CAT(bench_, BOOST_PP_CAT(__LINE__, n))(BOOST_PP_STRINGIZE(n), n);
=======
// default to running benchmark for 5000 iterations
BENCHMARK(CODE_TO_TIME, 5000);

 */

namespace benchmark {
// In case high_resolution_clock is steady, prefer that, otherwise use steady_clock.
struct best_clock {
    using hi_res_clock = std::chrono::high_resolution_clock;
    using steady_clock = std::chrono::steady_clock;
    using type = std::conditional<hi_res_clock::is_steady, hi_res_clock, steady_clock>::type;
};
using clock = best_clock::type;
using time_point = clock::time_point;
using duration = clock::duration;

class Printer;

class State
{
public:
    std::string m_name;
    uint64_t m_num_iters_left;
    const uint64_t m_num_iters;
    const uint64_t m_num_evals;
    std::vector<double> m_elapsed_results;
    time_point m_start_time;

    bool UpdateTimer(time_point finish_time);

    State(std::string name, uint64_t num_evals, double num_iters, Printer& printer) : m_name(name), m_num_iters_left(0), m_num_iters(num_iters), m_num_evals(num_evals)
    {
    }

    inline bool KeepRunning()
    {
        if (m_num_iters_left--) {
            return true;
        }

        bool result = UpdateTimer(clock::now());
        // measure again so runtime of UpdateTimer is not included
        m_start_time = clock::now();
        return result;
    }
};

typedef std::function<void(State&)> BenchFunction;

class BenchRunner
{
    struct Bench {
        BenchFunction func;
        uint64_t num_iters_for_one_second;
    };
    typedef std::map<std::string, Bench> BenchmarkMap;
    static BenchmarkMap& benchmarks();

public:
    BenchRunner(std::string name, BenchFunction func, uint64_t num_iters_for_one_second);

    static void RunAll(Printer& printer, uint64_t num_evals, double scaling, const std::string& filter, bool is_list_only);
};

// interface to output benchmark results.
class Printer
{
public:
    virtual ~Printer() {}
    virtual void header() = 0;
    virtual void result(const State& state) = 0;
    virtual void footer() = 0;
};

// default printer to console, shows min, max, median.
class ConsolePrinter : public Printer
{
public:
    void header();
    void result(const State& state);
    void footer();
};

// creates box plot with plotly.js
class PlotlyPrinter : public Printer
{
public:
    PlotlyPrinter(std::string plotly_url, int64_t width, int64_t height);
    void header();
    void result(const State& state);
    void footer();

private:
    std::string m_plotly_url;
    int64_t m_width;
    int64_t m_height;
};
}


// BENCHMARK(foo, num_iters_for_one_second) expands to:  benchmark::BenchRunner bench_11foo("foo", num_iterations);
// Choose a num_iters_for_one_second that takes roughly 1 second. The goal is that all benchmarks should take approximately
// the same time, and scaling factor can be used that the total time is appropriate for your system.
#define BENCHMARK(n, num_iters_for_one_second) \
    benchmark::BenchRunner BOOST_PP_CAT(bench_, BOOST_PP_CAT(__LINE__, n))(BOOST_PP_STRINGIZE(n), n, (num_iters_for_one_second));
>>>>>>> upstream/0.16

#endif // BITCOIN_BENCH_BENCH_H
