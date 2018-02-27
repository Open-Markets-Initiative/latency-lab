#ifndef OMI_LATENCY_RACE_HPP_
#define OMI_LATENCY_RACE_HPP_

#include <omi/latency/process/runs.hpp>
#include <omi/latency/race/options.hpp>
#include <omi/latency/race/layout.hpp>

// Latency race program template

namespace omi {
namespace latency {
namespace race {

// Default latency race program descriptions
struct defaults {
    static constexpr const char * title = "Latency Race";
    static constexpr const char * inbound = "events";
    static constexpr const char * outbound = "responses";
};

// Latency race html report program template
template <typename inbound, typename outbound, typename description = defaults>
void of(int argc, char *argv[]) {
    // Parse program options
    auto options = options::parse(argc, argv, description::title);

    // Load and match events
    auto results = process::runs<inbound, outbound, description>(options.directories, options.verbose);

    // Generate report
    if (options.verbose) { std::cout << "Generating Report" << std::endl; }
    layout race{options.report, results.runs(options.report.period)};

    // Write report
    race.write(options.path);
   
    // Program information
    if (options.verbose) { std::cout << options << std::endl; }
}

} } }

#endif