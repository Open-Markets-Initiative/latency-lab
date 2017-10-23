#ifndef OMI_LATENCY_REPORT_HPP_
#define OMI_LATENCY_REPORT_HPP_

#include <omi/match/events.hpp>
#include <omi/latency/report/options.hpp>
#include <omi/latency/report/components.hpp> 
#include <omi/utility/stopwatch.hpp>

// Single run omi html latency report generation

namespace omi {
namespace latency {
namespace report {

// Default program template settings
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
    if (options.verbose) { std::cout << description::title << std::endl; }

    stopwatch time; // need to make this better, add to options, with date?
      time.start();

    // Load all possible inbound trigger events
    if (options.verbose) { std::cout << "Loading inbound " << description::inbound << std::endl; }
    const auto inbounds = event::database<inbound>::read(options.files.inbound);
    if (options.verbose) { std::cout << inbounds; }

    // Load response events
    if (options.verbose) { std::cout << "Loading outbound " << description::outbound << std::endl; }  // Add fully qualified path
    const auto outbounds = event::list<outbound>::read(options.files.outbound);
    if (options.verbose) { std::cout << outbounds; }

    // Match events
    if (options.verbose) { std::cout << "Matching Events" << std::endl; }
    const auto events = match::events<inbound, outbound>{ inbounds, outbounds };
    if (options.verbose) { std::cout << events; }

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