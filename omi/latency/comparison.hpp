#ifndef OMI_LATENCY_COMPARISON_HPP_
#define OMI_LATENCY_COMPARISON_HPP_

#include <omi/latency/process/runs.hpp>
#include <omi/latency/comparison/options.hpp>
#include <omi/latency/comparison/layout.hpp>

// Latency comparison program template

namespace omi {
namespace latency {
namespace comparison {

// Default comparison program decsriptions
struct defaults {
    static constexpr const char * title = "Latency Comparison Report";
    static constexpr const char * inbound = "events";
    static constexpr const char * outbound = "responses";
};

// Latency comparison html report program template
template <typename inbound, typename outbound, typename description = defaults>
void of(int argc, char *argv[]) {
	// Parse program options
	auto options = options::parse(argc, argv, description::title);

    // Load and match events
    auto results = process::runs<inbound, outbound, description>(options.directories, options.verbose);

    // Generate report
    if (options.verbose) { std::cout << "Generating Report" << std::endl; }
    layout comparison{options.report, results.runs(options.report.period)};

    // Write report
    comparison.write(options.path);
   
    // Program information
    if (options.verbose) { std::cout << options << std::endl; }
}

} } }

#endif