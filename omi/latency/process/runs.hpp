#ifndef OMI_LATENCY_PROCESS_RUNS_HPP_
#define OMI_LATENCY_PROCESS_RUNS_HPP_

#include <iostream>

#include <omi/match/events.hpp>
#include <omi/match/results.hpp>
#include <omi/match/inputs.hpp>
#include <omi/directory/parsing.hpp>
#include <omi/compare/natural.hpp>

// Process multiple run latency matching

namespace omi::latency::process {

template <typename inbound, typename outbound, typename description>
auto runs(const match::inputs &directory, const bool verbose) {
    // Print title
    if (verbose) { std::cout << description::title << std::endl; }

    // Search directories for matching latency data files
    auto runs = directory::parse(directory.inbound, directory.outbound);
    if (verbose) { std::cout << "Directories have " << runs.size() << " data sets" << std::endl; }

    // Sort runs by natural order
    std::sort(runs.begin(), runs.end(), [](const auto & a, const auto & b) { return compare::natural(a.inbound.string(), b.inbound.string()); } );


    // TODO: add parsing verbose output per run (allow this to be run in parallel)

    // Stores test name key, delta value
    match::results<inbound, outbound> results;
    for (auto&& run : runs) {
        auto name = directory::name(directory.inbound);
        auto events = match::events<inbound, outbound>(run);
        results.push_back(match::result<inbound, outbound>{ name, run, events });
    }

    return results;
};

}

#endif