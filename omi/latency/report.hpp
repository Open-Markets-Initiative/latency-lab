#ifndef OMI_LATENCY_REPORT_HPP_
#define OMI_LATENCY_REPORT_HPP_

#include <omi/latency/report/components.hpp>
#include <omi/latency/report/options.hpp>
#include <omi/latency/process/run.hpp>

// Single run omi html latency report generation

namespace omi {
namespace latency {
namespace report {

// Default template settings
struct defaults {
    static constexpr const char * title = "Generate Latency Report";
    static constexpr const char * inbound = "events";
    static constexpr const char * outbound = "responses";
};

// Latency report program template
template <typename inbound, typename outbound, typename titles = defaults>
void of(int argc, char *argv[]) {
    // Parse program options for settings
    auto options = options::parse(argc, argv);

    // Load and match events
    auto result = process::run<inbound, outbound, titles>(options.files, options.verbose);

    // Configure and write report
    if (options.verbose) { std::cout << "Generating Html Report" << std::endl; }
    auto report = generate<inbound, outbound>(options.report, result);
      report.write(options.path);

    // Program information
    if (options.verbose) { std::cout << options << std::endl; }
}

} } }

#endif