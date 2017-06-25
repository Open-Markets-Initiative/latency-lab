#ifndef OMI_LATENCY_REPORT_DECLARATIONS_HPP_
#define OMI_LATENCY_REPORT_DECLARATIONS_HPP_

#include <omi/event/matcher.hpp>
#include <omi/latency/report/options.hpp>
#include <omi/latency/report/components.hpp> 

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
    const auto inbounds = event::database<inbound>::read(options.files.inbound);
    if (options.verbose) { std::cout << inbounds; }

    // Load response events
    if (options.verbose) { std::cout << "Loading outbound " << outbound::description << " responses" << std::endl; } // add file with boost filesystem
    const auto outbounds = event::responses<outbound>::read(options.files.outbound);
    if (options.verbose) { std::cout << outbounds; }

    // Match events
    if (options.verbose) { std::cout << "Matching Events" << std::endl; }
    const auto matched = event::matcher<inbound, outbound>{ inbounds, outbounds };
    if (options.verbose) { std::cout << matched; }

    // Generate report
    if (options.verbose) { std::cout << "Generating Report" << std::endl; }
    components report;
      report.layout = options.report;
      report.files = options.files;
      report.data = matched.matched.deltas();
    report.write(options.path);
};

} } }

#endif
