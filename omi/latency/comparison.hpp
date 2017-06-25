#ifndef OMI_LATENCY_COMPARISON_DECLARATIONS_HPP
#define OMI_LATENCY_COMPARISON_DECLARATIONS_HPP

#include <omi/event/matcher.hpp>
#include <omi/latency/comparison/options.hpp>
#include <omi/latency/comparison/components.hpp>
#include <boost/filesystem.hpp>

namespace omi {
namespace latency {
namespace comparison {

const std::string INBOUND_EVENT_SUFFIX = "inbound.events";
const std::string OUTBOUND_EVENT_SUFFIX = "outbound.events";

using namespace boost::filesystem;

template <class inbound, class outbound>
void generate(int argc, char *argv[]) {
	// Parse program options for settings
    auto options = comparison::options::parse(argc, argv);
    if (options.verbose) { std::cout << "Generate Latency Comparison Report" << std::endl; }

	// Stores test name key, delta value
	std::map<std::string, std::vector<double>> delta_map;

	// loop through the directory for each inbound events
	// TODO: refactor options::event::inputs to separate directory from files
	//std::cout << ">> directory " << options.files.dir << std::endl;
	path p = options.files.dir;

	try {
		if (exists(p) && is_directory(p)) {

			std::cout << p << " is a directory containing:\n";
			for (directory_entry& x : directory_iterator(p)) {
				std::string inboundFile = x.path().filename().string();
				auto i = inboundFile.find(INBOUND_EVENT_SUFFIX);

				if (i != std::string::npos) {
					std::cout << " inbound : " << inboundFile << std::endl;
					std::string test_name = inboundFile.substr(0, i-1);
					std::string outboundFile = inboundFile.substr(0,i)+ OUTBOUND_EVENT_SUFFIX;
					std::cout << " outbound : " << outboundFile << std::endl;

					// Load all inbound events for trigger matching
					if (options.verbose) {
						std::cout << "Loading inbound " << inbound::description << " events" << std::endl;
					}

					const auto inbounds = event::database<inbound>::read(options.files.dir+"/"+inboundFile);
					if (options.verbose) { std::cout << inbounds; }

					// Load response events
					if (options.verbose) { std::cout << "Loading outbound " << outbound::description << " responses" << std::endl; }
					const auto outbounds = event::responses<outbound>::read(options.files.dir+"/"+outboundFile);
					if (options.verbose) { std::cout << outbounds; }

					// Match events
					if (options.verbose) { std::cout << "Matching Events" << std::endl; }
					const auto matched = event::matcher<inbound, outbound>{inbounds, outbounds};
					if (options.verbose) { std::cout << matched; }

					if (options.verbose) { std::cout << test_name << " events added" << std::endl; }
					delta_map.insert(std::make_pair(test_name, matched.matches.deltas()));

					}
			}
		} else {
			std::cout << p << " does not exist\n";
		}

		// Generate report
		if (options.verbose) { std::cout << "Generating Report" << std::endl; }
		comparison::components report;
		  report.layout = options.report;
		  report.files = options.files;
		  report.delta_map = delta_map;
		  report.write(options.path);

		} catch (const filesystem_error& ex) {
			std::cout << ex.what() << '\n';
		}
	}}
}}

#endif