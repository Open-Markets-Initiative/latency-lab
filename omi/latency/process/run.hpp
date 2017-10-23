#ifndef OMI_LATENCY_PROCESS_RUN_HPP_
#define OMI_LATENCY_PROCESS_RUN_HPP_

#include <omi/match/events.hpp>
#include <omi/match/inputs.hpp>

// Single run omi html latency match processing

namespace omi {
namespace latency {
namespace process {

template <typename inbound, typename outbound, typename description>
match::events<inbound, outbound> run(const match::inputs &file, const bool verbose) {
    // Print title
    if (verbose) { std::cout << description::title << std::endl; }

    // Load all possible inbound trigger events
    if (verbose) { std::cout << "Loading inbound " << description::inbound << std::endl; }
    const auto inbounds = event::database<inbound>::read(file.inbound);
    if (verbose) { std::cout << inbounds; }

    // Load response events
    if (verbose) { std::cout << "Loading outbound " << description::outbound << std::endl; }  // Add fully qualified path
    const auto outbounds = event::list<outbound>::read(file.outbound);
    if (verbose) { std::cout << outbounds; }

    // Match events
    if (verbose) { std::cout << "Matching Events" << std::endl; }
    auto events = match::events<inbound, outbound>{ inbounds, outbounds };
    if (verbose) { std::cout << events; }

    return events;
};

} } }

#endif