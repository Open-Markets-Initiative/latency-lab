#ifndef OMI_LATENCY_REPORT_HPP_
#define OMI_LATENCY_REPORT_HPP_

#include <omi/latency/report/options.hpp>
#include <omi/latency/report/components.hpp>
#include <omi/latency/process/run.hpp>
#include <omi/utility/stopwatch.hpp>

// Single run omi html latency report generation

namespace omi {
namespace latency {
namespace report {

// Default template settings
struct description {
    static constexpr const char * title = "Generate Latency Report";
    static constexpr const char * inbound = "events";
    static constexpr const char * outbound = "responses";
};

// Latency report program template
template <typename inbound, typename outbound, typename description = description>
void of(int argc, char *argv[]) {
    // Parse program options for settings
    auto options = options::parse(argc, argv);
    stopwatch time; // need to make this better, add to opptions, with date?
      time.start();

    // Load files and match events
    auto events = process::run<inbound, outbound, description>(options.files, options.verbose);

    // Configure options
    components report;
      report.layout = options.report;
      report.files = options.files;
      report.data = event::transform(events.matched.deltas(), [](const auto &current) { return current.microseconds(); }); // make a fluent version

    // Generate report
    if (options.verbose) { std::cout << "Generating Html Report" << std::endl; }
    report.write(options.path);

    time.stop();
    if (options.verbose) { std::cout << time << std::endl; }
};

} } }

#endif