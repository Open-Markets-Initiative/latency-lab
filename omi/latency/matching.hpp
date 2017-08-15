#ifndef OMI_LATENCY_MATCHING_HPP_
#define OMI_LATENCY_MATCHING_HPP_

#include <omi/match/events.hpp>
#include <omi/latency/matching/options.hpp>

// Latency event matching program template

namespace omi {
namespace latency {
namespace matching {

    // Default email program template notes 
struct description {
    static constexpr char * title = "Matched Event List";
    static constexpr char * inbound = "events";
    static constexpr char * outbound = "responses";
};

template <class inbound, class outbound, class description = description>
void of(int argc, char *argv[]) {
    // Parse program options for settings
    auto options = options::parse(argc, argv);
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
    const auto events = match::events<inbound, outbound> { inbounds, outbounds };
    if (options.verbose) { std::cout << events; }

    // Writes matches file 
    events.matched.infos(options.path);

    // TODO: allow matches, infos and/or ids based on optional args
};

} } }

#endif