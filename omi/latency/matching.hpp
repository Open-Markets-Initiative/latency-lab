#ifndef OMI_LATENCY_MATCHING_HPP_
#define OMI_LATENCY_MATCHING_HPP_

#include <omi/latency/matching/options.hpp>
#include <omi/latency/process/run.hpp>

// Latency event matching program template

namespace omi {
namespace latency {
namespace matching {

// Default program template settings
struct description {
    static constexpr const char * title = "Matched Event List";
    static constexpr const char * inbound = "events";
    static constexpr const char * outbound = "responses";
};

// Latency event matching program template
template <typename inbound, typename outbound, typename description = description>
void of(int argc, char *argv[]) {
    // Parse program options for settings
    auto options = options::parse(argc, argv);
    // Load files and match events
    auto events = process::run<inbound, outbound, description>(options.files, options.verbose);
    // Writes matches to file 
    events.matched.infos(options.path);

    // TODO: allow matches, infos and/or ids based on optional args
};

} } }

#endif 