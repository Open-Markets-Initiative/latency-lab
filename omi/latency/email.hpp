#ifndef OMI_LATENCY_EMAIL_HPP_
#define OMI_LATENCY_EMAIL_HPP_

#include <omi/latency/process/run.hpp>
#include <omi/latency/email/options.hpp>
#include <omi/latency/email/components.hpp> 
#include <omi/utility/stopwatch.hpp>

// Single run omi html only latency report generation

namespace omi {
namespace latency {
namespace email {

// Default email program template notes 
struct description {
    static constexpr const char * title = "Generate Emailable Latency Report";
    static constexpr const char * inbound = "events";
    static constexpr const char * outbound = "responses";
};

// Latency report program template
template <class inbound, class outbound, class description = description>
void of(int argc, char *argv[]) {
    // Parse program options for settings
    auto options = options::parse(argc, argv);
    stopwatch time; // need to make this better, add to opptions, with date?
      time.start();

    // Load files and match events
    auto events = process::run<inbound, outbound, description>(options.files, options.verbose);

    email::components email;
      email.layout = options.email;
      email.matching.path = options.files;
      email.matching.data = event::transform(events.matched, [](const auto &current) { return current.timestamps().delta().microseconds(); });

    // Generate report
    if (options.verbose) { std::cout << "Generating Html Latency Report Email" << std::endl; }
    email.write(options.path);

    time.stop();
    if (options.verbose) { std::cout << time << std::endl; }
};

} } }

#endif
