#ifndef OMI_LATENCY_COMPARISON_HPP_
#define OMI_LATENCY_COMPARISON_HPP_

#include <omi/event/matcher.hpp>
#include <omi/latency/comparison/options.hpp>
#include <omi/latency/comparison/components.hpp>
#include <boost/filesystem.hpp>

// Latency comparison program template

namespace omi {
namespace latency {
namespace comparison {

const std::string INBOUND_EVENT_SUFFIX = "inbound.events";
const std::string OUTBOUND_EVENT_SUFFIX = "outbound.events";

// Latency comparison program template
template <class inbound, class outbound>
void of(int argc, char *argv[]) {
	// Parse program options for settings
	auto options = comparison::options::parse(argc, argv);
	if (options.verbose) { std::cout << "Generate Latency Comparison Report" << std::endl; }

	// Stores test name key, delta value
	std::map<std::string, std::vector<double>> delta_map;

	// loop through the directory for each inbound events
	// TODO: refactor options::event::inputs to separate directory from files
	boost::filesystem::path path = options.directory;
	if (not boost::filesystem::exists(path) or not boost::filesystem::is_directory(path)) {
		throw std::invalid_argument("Invalid directory: " + options.directory);
	}

	std::cout << path << " is a directory containing:\n";
	for (boost::filesystem::directory_entry& x : boost::filesystem::directory_iterator(path)) {
		auto inboundFile = x.path().filename().string();
		auto i = inboundFile.find(INBOUND_EVENT_SUFFIX);

		if (i != std::string::npos) {
			std::cout << " inbound : " << inboundFile << std::endl;
			auto test_name = inboundFile.substr(0, i - 1);
			auto outboundFile = inboundFile.substr(0, i) + OUTBOUND_EVENT_SUFFIX;
			std::cout << " outbound : " << outboundFile << std::endl;

			// Load all inbound events for trigger matching
			if (options.verbose) {
				std::cout << "Loading inbound " << inbound::description << " events" << std::endl;
			}

			const auto inbounds = event::database<inbound>::read(options.directory + "/" + inboundFile);
			if (options.verbose) { std::cout << inbounds; }

			// Load response events
			if (options.verbose) { std::cout << "Loading outbound " << outbound::description << " responses" << std::endl; }
			const auto outbounds = event::responses<outbound>::read(options.directory + "/" + outboundFile);
			if (options.verbose) { std::cout << outbounds; }

			// Match events
			if (options.verbose) { std::cout << "Matching Events" << std::endl; }
			const auto matched = event::matcher<inbound, outbound> {inbounds, outbounds};
			if (options.verbose) { std::cout << matched; }

			if (options.verbose) { std::cout << test_name << " events added" << std::endl; }
			delta_map.insert(std::make_pair(test_name, matched.matched.deltas()));

		}
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