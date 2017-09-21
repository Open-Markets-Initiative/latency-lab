#ifndef OMI_LATENCY_ANALYSIS_HPP_
#define OMI_LATENCY_ANALYSIS_HPP_

#include <omi/match/events.hpp>
#include <omi/analysis/results.hpp>
#include <omi/latency/analysis/options.hpp>

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
    auto options = options::parse(argc, argv, description::title);
    if (options.verbose) { std::cout << description::title << std::endl; }

    // Load all possible inbound trigger events
    if (options.verbose) { std::cout << "Loading inbound " << description::inbound << std::endl; }
    const auto inbounds = event::database<inbound>::read(options.files.inbound);
    if (options.verbose) { std::cout << inbounds; }

    // Load response events
    if (options.verbose) { std::cout << "Loading outbound " << description::outbound << std::endl; }
    const auto outbounds = event::responses<outbound>::read(options.files.outbound);
    if (options.verbose) { std::cout << outbounds; }

    // Match events
    if (options.verbose) { std::cout << "Matching Events" << std::endl; }
    const auto events = match::events<inbound, outbound>(inbounds, outbounds);
    if (options.verbose) { std::cout << events; }

    std::cout << omi::analysis::results{ events.matched.deltas() };
};

} } }

#endif
