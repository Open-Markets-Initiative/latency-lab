#ifndef OMI_LATENCY_PROCESS_RUN_HPP_
#define OMI_LATENCY_PROCESS_RUN_HPP_

#include <omi/match/results.hpp>

#include <iostream>

// Process single run latency matching

namespace omi {
namespace latency {
namespace process {

template <typename inbound, typename outbound, typename description>
auto run(const match::inputs &file, const bool verbose) {
    // Print title
    if (verbose) { std::cout << description::title << std::endl; }

    // Load all possible inbound trigger events
    if (verbose) { std::cout << "Loading inbound " << description::inbound << std::endl; }
    const auto inbounds = event::dictionary<inbound>::read(file.inbound);
    if (verbose) { std::cout << inbounds; }

    // Load response events
    if (verbose) { std::cout << "Loading outbound " << description::outbound << std::endl; }  // Todo theses should be fully qualified path objects and return those1
    const auto outbounds = event::list<outbound>::read(file.outbound);
    if (verbose) { std::cout << outbounds; }

    // Match events
    if (verbose) { std::cout << "Matching Events" << std::endl; }
    auto events = match::events<inbound, outbound>{ inbounds, outbounds };
    if (verbose) { std::cout << events; }

    // Create name and return result
    auto name = std::string(description::inbound) + std::string(" to ") + std::string(description::outbound);
    return match::result<inbound, outbound>{ name, file, events };
}

} } }

#endif