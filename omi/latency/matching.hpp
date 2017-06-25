#ifndef OMI_LATENCY_MATCHING_HPP_
#define OMI_LATENCY_MATCHING_HPP_

#include <omi/event/matcher.hpp>
#include <omi/latency/matching/options.hpp>

// Latency event matching

namespace omi {
namespace latency {
namespace matching {

template <class inbound, class outbound>
void generate(int argc, char *argv[]) {
    // Add timer 
    // Add date

    // Parse program options for settings
    auto options = options::parse(argc, argv);
    if (options.verbose) { std::cout << "Match inbound and outbound events" << std::endl; }

    // Load all inbound events for trigger matching
    if (options.verbose) { std::cout << "Loading inbound " << inbound::description << " events" << std::endl; }
    const auto inbounds = event::database<inbound>::read(options.files.inbound);
    if (options.verbose) { std::cout << inbounds; }

    // Load response events
    if (options.verbose) { std::cout << "Loading outbound " << outbound::description << " responses" << std::endl; }
    const auto outbounds = event::responses<outbound>::read(options.files.outbound);
    if (options.verbose) { std::cout << outbounds; }

    // Match events
    if (options.verbose) { std::cout << "Matching Events" << std::endl; }
    const auto matched = event::matcher<inbound, outbound> { inbounds, outbounds };
    if (options.verbose) { std::cout << matched; }

    // Writes matches file 
    // TODO: (allow matches infos and/or ids based on optional args
    matched.matched.infos(options.path);
};

} } }

#endif