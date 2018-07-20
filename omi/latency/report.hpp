#ifndef OMI_LATENCY_REPORT_HPP_
#define OMI_LATENCY_REPORT_HPP_

#include <omi/latency/report/options.hpp>
#include <omi/latency/report/layout.hpp>
#include <omi/latency/process/run.hpp>

// Single run omi html latency report generation

namespace omi::latency::report {

// Default template settings
struct defaults {
    static constexpr const char * title = "Generate Latency Report";
    static constexpr const char * inbound = "events";
    static constexpr const char * outbound = "responses";
};

// Latency report program template
template <typename inbound, typename outbound, typename descriptions = defaults>
void of(const int argc, char *argv[]) {
    // Parse program options
    auto options = options::parse(argc, argv);

    // Load and match events
    auto result = process::run<inbound, outbound, descriptions>(options.files, options.verbose);

    // Determine report period and precision
    if (not options.report.precision.chart.is_initialized()) { // make a method for this
        options.report.precision.chart = 3;
    }
    if (not options.report.precision.statistics.is_initialized()) {
        options.report.precision.statistics = 4;
    }
    if (not options.report.precision.percentiles.is_initialized()) {
        options.report.precision.percentiles = 3;
    }

    // Configure report
    if (options.verbose) { std::cout << "Generating Html Report" << std::endl; }
    layout report{ options.report, result.run(options.report.period) };

    // Write report
    report.write(options.report.path);

    // Program information
    if (options.verbose) { std::cout << options << std::endl; }
}

}

#endif