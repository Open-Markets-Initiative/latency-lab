#ifndef OMI_LATENCY_REPORT_DECLARATIONS_HPP_
#define OMI_LATENCY_REPORT_DECLARATIONS_HPP_

#include <omi/wireshark/matcher.hpp>
#include <omi/latency/report/components.hpp> 
#include <omi/latency/report/options.hpp>

// Templates for single run omi html latency report generation

namespace omi { 
namespace latency {
namespace report {

// Templated "main" for report generation
template <class inbound, class outbound>
void generate(int argc, char *argv[]) {
	// Parse program options for settings
	auto options = options::parse(argc, argv);
	if (options.verbose) { std::cout << "Generate Example Html Report" << std::endl; }

	// Match events
	const auto wireshark = omi::wireshark::matcher<inbound, outbound>{ options.files };

	// Generate report
	components report;
	  report.layout = options.report;
	  report.files = options.files;
	  report.data = wireshark.events.deltas().values(); // Need to make this better
	report.write(options.path);
};

} } }

#endif