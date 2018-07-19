#ifndef OMI_LATENCY_ANALYSIS_HPP_
#define OMI_LATENCY_ANALYSIS_HPP_

#include <omi/analysis/results.hpp>
#include <omi/latency/analysis/options.hpp>
#include <omi/latency/process/run.hpp>

// Latency analysis program template

namespace omi::latency::analysis {

// Analysis program defaults
struct defaults {
    static constexpr const char * title = "Latency Analysis";
    static constexpr const char * inbound = "events";
    static constexpr const char * outbound = "responses";
};

// Default analysis program template
template <class inbound, class outbound, class descriptions = defaults>
void of(int argc, char *argv[]) {
    // Parse program options for settings
    auto options = options::parse(argc, argv);

    // Load files and match events
    auto result = process::run<inbound, outbound, descriptions>(options.files, options.verbose);

    // Analyze data
    auto deltas = result.deltas(options.period);
    std::cout << omi::analysis::of(deltas);
    std::cout << options;
}

}

#endif