<<<<<<< HEAD
// Copyright (c) 2015-2016 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "bench.h"
#include "perf.h"
=======
// Copyright (c) 2015-2017 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <bench/bench.h>
#include <bench/perf.h>
>>>>>>> upstream/0.16

#include <assert.h>
#include <iostream>
#include <iomanip>
<<<<<<< HEAD
#include <sys/time.h>

benchmark::BenchRunner::BenchmarkMap &benchmark::BenchRunner::benchmarks() {
    static std::map<std::string, benchmark::BenchFunction> benchmarks_map;
    return benchmarks_map;
}

static double gettimedouble(void) {
    struct timeval tv;
    gettimeofday(&tv, nullptr);
    return tv.tv_usec * 0.000001 + tv.tv_sec;
}

benchmark::BenchRunner::BenchRunner(std::string name, benchmark::BenchFunction func)
{
    benchmarks().insert(std::make_pair(name, func));
}

void
benchmark::BenchRunner::RunAll(double elapsedTimeForOne)
{
    perf_init();
    std::cout << "#Benchmark" << "," << "count" << "," << "min" << "," << "max" << "," << "average" << ","
              << "min_cycles" << "," << "max_cycles" << "," << "average_cycles" << "\n";

    for (const auto &p: benchmarks()) {
        State state(p.first, elapsedTimeForOne);
        p.second(state);
    }
    perf_fini();
}

bool benchmark::State::KeepRunning()
{
    if (count & countMask) {
      ++count;
      return true;
    }
    double now;
    uint64_t nowCycles;
    if (count == 0) {
        lastTime = beginTime = now = gettimedouble();
        lastCycles = beginCycles = nowCycles = perf_cpucycles();
    }
    else {
        now = gettimedouble();
        double elapsed = now - lastTime;
        double elapsedOne = elapsed * countMaskInv;
        if (elapsedOne < minTime) minTime = elapsedOne;
        if (elapsedOne > maxTime) maxTime = elapsedOne;

        // We only use relative values, so don't have to handle 64-bit wrap-around specially
        nowCycles = perf_cpucycles();
        uint64_t elapsedOneCycles = (nowCycles - lastCycles) * countMaskInv;
        if (elapsedOneCycles < minCycles) minCycles = elapsedOneCycles;
        if (elapsedOneCycles > maxCycles) maxCycles = elapsedOneCycles;

        if (elapsed*128 < maxElapsed) {
          // If the execution was much too fast (1/128th of maxElapsed), increase the count mask by 8x and restart timing.
          // The restart avoids including the overhead of this code in the measurement.
          countMask = ((countMask<<3)|7) & ((1LL<<60)-1);
          countMaskInv = 1./(countMask+1);
          count = 0;
          minTime = std::numeric_limits<double>::max();
          maxTime = std::numeric_limits<double>::min();
          minCycles = std::numeric_limits<uint64_t>::max();
          maxCycles = std::numeric_limits<uint64_t>::min();
          return true;
        }
        if (elapsed*16 < maxElapsed) {
          uint64_t newCountMask = ((countMask<<1)|1) & ((1LL<<60)-1);
          if ((count & newCountMask)==0) {
              countMask = newCountMask;
              countMaskInv = 1./(countMask+1);
          }
        }
    }
    lastTime = now;
    lastCycles = nowCycles;
    ++count;

    if (now - beginTime < maxElapsed) return true; // Keep going

    --count;

    assert(count != 0 && "count == 0 => (now == 0 && beginTime == 0) => return above");

    // Output results
    double average = (now-beginTime)/count;
    int64_t averageCycles = (nowCycles-beginCycles)/count;
    std::cout << std::fixed << std::setprecision(15) << name << "," << count << "," << minTime << "," << maxTime << "," << average << ","
              << minCycles << "," << maxCycles << "," << averageCycles << "\n";
    std::cout.copyfmt(std::ios(nullptr));

    return false;
=======
#include <algorithm>
#include <regex>
#include <numeric>

void benchmark::ConsolePrinter::header()
{
    std::cout << "# Benchmark, evals, iterations, total, min, max, median" << std::endl;
}

void benchmark::ConsolePrinter::result(const State& state)
{
    auto results = state.m_elapsed_results;
    std::sort(results.begin(), results.end());

    double total = state.m_num_iters * std::accumulate(results.begin(), results.end(), 0.0);

    double front = 0;
    double back = 0;
    double median = 0;

    if (!results.empty()) {
        front = results.front();
        back = results.back();

        size_t mid = results.size() / 2;
        median = results[mid];
        if (0 == results.size() % 2) {
            median = (results[mid] + results[mid + 1]) / 2;
        }
    }

    std::cout << std::setprecision(6);
    std::cout << state.m_name << ", " << state.m_num_evals << ", " << state.m_num_iters << ", " << total << ", " << front << ", " << back << ", " << median << std::endl;
}

void benchmark::ConsolePrinter::footer() {}
benchmark::PlotlyPrinter::PlotlyPrinter(std::string plotly_url, int64_t width, int64_t height)
    : m_plotly_url(plotly_url), m_width(width), m_height(height)
{
}

void benchmark::PlotlyPrinter::header()
{
    std::cout << "<html><head>"
              << "<script src=\"" << m_plotly_url << "\"></script>"
              << "</head><body><div id=\"myDiv\" style=\"width:" << m_width << "px; height:" << m_height << "px\"></div>"
              << "<script> var data = ["
              << std::endl;
}

void benchmark::PlotlyPrinter::result(const State& state)
{
    std::cout << "{ " << std::endl
              << "  name: '" << state.m_name << "', " << std::endl
              << "  y: [";

    const char* prefix = "";
    for (const auto& e : state.m_elapsed_results) {
        std::cout << prefix << std::setprecision(6) << e;
        prefix = ", ";
    }
    std::cout << "]," << std::endl
              << "  boxpoints: 'all', jitter: 0.3, pointpos: 0, type: 'box',"
              << std::endl
              << "}," << std::endl;
}

void benchmark::PlotlyPrinter::footer()
{
    std::cout << "]; var layout = { showlegend: false, yaxis: { rangemode: 'tozero', autorange: true } };"
              << "Plotly.newPlot('myDiv', data, layout);"
              << "</script></body></html>";
}


benchmark::BenchRunner::BenchmarkMap& benchmark::BenchRunner::benchmarks()
{
    static std::map<std::string, Bench> benchmarks_map;
    return benchmarks_map;
}

benchmark::BenchRunner::BenchRunner(std::string name, benchmark::BenchFunction func, uint64_t num_iters_for_one_second)
{
    benchmarks().insert(std::make_pair(name, Bench{func, num_iters_for_one_second}));
}

void benchmark::BenchRunner::RunAll(Printer& printer, uint64_t num_evals, double scaling, const std::string& filter, bool is_list_only)
{
    perf_init();
    if (!std::ratio_less_equal<benchmark::clock::period, std::micro>::value) {
        std::cerr << "WARNING: Clock precision is worse than microsecond - benchmarks may be less accurate!\n";
    }
#ifdef DEBUG
    std::cerr << "WARNING: This is a debug build - may result in slower benchmarks.\n";
#endif

    std::regex reFilter(filter);
    std::smatch baseMatch;

    printer.header();

    for (const auto& p : benchmarks()) {
        if (!std::regex_match(p.first, baseMatch, reFilter)) {
            continue;
        }

        uint64_t num_iters = static_cast<uint64_t>(p.second.num_iters_for_one_second * scaling);
        if (0 == num_iters) {
            num_iters = 1;
        }
        State state(p.first, num_evals, num_iters, printer);
        if (!is_list_only) {
            p.second.func(state);
        }
        printer.result(state);
    }

    printer.footer();

    perf_fini();
}

bool benchmark::State::UpdateTimer(const benchmark::time_point current_time)
{
    if (m_start_time != time_point()) {
        std::chrono::duration<double> diff = current_time - m_start_time;
        m_elapsed_results.push_back(diff.count() / m_num_iters);

        if (m_elapsed_results.size() == m_num_evals) {
            return false;
        }
    }

    m_num_iters_left = m_num_iters - 1;
    return true;
>>>>>>> upstream/0.16
}
