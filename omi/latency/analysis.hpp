#ifndef OMI_LATENCY_ANALYSIS_HPP_
#define OMI_LATENCY_ANALYSIS_HPP_

#include <omi/analysis/results.hpp>
#include <omi/latency/analysis/options.hpp>
#include <omi/latency/process/run.hpp>

// Latency analysis program template

namespace omi {
namespace latency {
namespace analysis {

// Default analysis program template notes 
struct description {
    static constexpr const char * title = "Latency Analysis";
    static constexpr const char * inbound = "events";
    static constexpr const char * outbound = "responses";
};

template <class inbound, class outbound, class description = description>
void of(int argc, char *argv[]) {
    // Parse program options for settings
    auto options = options::parse(argc, argv);
    // Load files and match events
    auto events = process::run<inbound, outbound, description>(options.files, options.verbose);
    // Print results
    auto deltas = event::transform(events.matched, [](const auto &current) { return current.timestamps().delta().microseconds(); });
    std::cout << omi::analysis::results<decltype(deltas)>{ deltas };
};

} } }

#endif
