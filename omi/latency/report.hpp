#ifndef OMI_LATENCY_REPORT_DECLARATIONS_HPP_
#define OMI_LATENCY_REPORT_DECLARATIONS_HPP_

#include <omi/event/matcher.hpp>
#include <omi/analysis/deltas.hpp>
#include <omi/latency/report/components.hpp> 
#include <omi/latency/report/options.hpp>

// Single run omi html latency report generation

namespace omi { 
namespace latency {
namespace report {

template <class inbound, class outbound>
void generate(int argc, char *argv[]) {
    // Add timer 
    // Add date

    // Parse program options for settings
    auto options = options::parse(argc, argv);
    if (options.verbose) { std::cout << "Generate Latency Report" << std::endl; }

    // Load all inbound events for trigger matching
    if (options.verbose) { std::cout << "Loading inbound " << inbound::description << " events" << std::endl; }
    const auto inbounds = event::database<inbound>{ options.files.inbound };
    if (options.verbose) { std::cout << inbounds; }

    // Load response events
    if (options.verbose) { std::cout << "Loading outbound " << outbound::description << " responses" << std::endl; } // add file with boost filesystem
    const auto outbounds = event::responses<outbound>{ options.files.outbound };
    if (options.verbose) { std::cout << outbounds; }

    // Match events
    if (options.verbose) { std::cout << "Matching Events" << std::endl; }
    const auto matched = event::matcher<inbound, outbound>{ inbounds, outbounds };
    if (options.verbose) { std::cout << matched; }

    // Generate report
    if (options.verbose) { std::cout << "Generating Report" << std::endl; }

    analysis::deltas deltas;
    for (const auto &match : matched.matches) {     
        deltas.push_back(analysis::delta(match.inbound.microseconds(), match.outbound.microseconds())); // how to handle this with tmp?
    }

    components report;
      report.layout = options.report;
      report.files = options.files;
      report.data = deltas.values();
    report.write(options.path);
};

} } }

#endif
