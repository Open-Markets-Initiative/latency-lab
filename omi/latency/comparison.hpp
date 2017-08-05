#ifndef OMI_LATENCY_COMPARISON_HPP_
#define OMI_LATENCY_COMPARISON_HPP_

#include <omi/event/matcher.hpp>
#include <omi/directory/parsing.hpp>
#include <omi/latency/comparison/options.hpp>
#include <omi/latency/comparison/components.hpp>

// Latency comparison program template

namespace omi {
namespace latency {
namespace comparison {

// Latency comparison html report program template
template <class inbound, class outbound>
void of(int argc, char *argv[]) {
	// Parse program options for settings
	auto options = options::parse(argc, argv);
	if (options.verbose) { std::cout << "Generate Latency Comparison Report" << std::endl; }

    // Search directories for matching latency data files
    auto runs = directory::parse(options.directory.inbound, options.directory.outbound);
	if (options.verbose) { std::cout << "Directories have " << runs.size() << " matching data sets" << std::endl; }

    // Stores test name key, delta value
    std::map<std::string, std::vector<double>> delta_map;
    for (const auto& run : runs) {
        auto name = directory::name(run.inbound);
        auto matched = event::matcher<inbound, outbound> {run.inbound, run.outbound};
        delta_map.insert(std::make_pair(name, matched.matched.deltas()));
    }

    comparison::components report;
      report.layout = options.report;
      report.delta_map = delta_map;

	// Generate report
	if (options.verbose) { std::cout << "Generating Report" << std::endl; }
	report.write(options.path);
}

} } }

#endif