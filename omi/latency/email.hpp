#ifndef OMI_LATENCY_EMAIL_HPP_
#define OMI_LATENCY_EMAIL_HPP_

#include <omi/match/events.hpp>
#include <omi/latency/email/options.hpp>
#include <omi/latency/email/components.hpp> 
#include <omi/utility/stopwatch.hpp>

// Single run omi html latency report generation

namespace omi {
namespace latency {
namespace email {

// Latency report program template
template <class inbound, class outbound>
void of(int argc, char *argv[]) {
    // TODO: static assert on descriptions

    // Parse program options for settings
    auto options = options::parse(argc, argv);
    if (options.verbose) { std::cout << "Generate Emailable Latency Report" << std::endl; }

    stopwatch time; // need to make this better, add to opptions, with date?
      time.start();

    // Load all inbound events for trigger matching
    if (options.verbose) { std::cout << "Loading inbound " << inbound::description << " events" << std::endl; }
    const auto inbounds = event::database<inbound>::read(options.files.inbound);
    if (options.verbose) { std::cout << inbounds; }

    // Load response records
    if (options.verbose) { std::cout << "Loading outbound " << outbound::description << " responses" << std::endl; } // add full qualified path with boost filesystem
    const auto outbounds = event::responses<outbound>::read(options.files.outbound);
    if (options.verbose) { std::cout << outbounds; }

    // Match events
    if (options.verbose) { std::cout << "Matching Events" << std::endl; }
    const auto events = match::events<inbound, outbound>{ inbounds, outbounds };
    if (options.verbose) { std::cout << events; }

    components email;
      email.layout = options.email;
      email.files = options.files;
      email.data = events.matched.deltas();

    // Generate report
    if (options.verbose) { std::cout << "Generating Html Latency Report Email" << std::endl; }
    email.write(options.path);

    time.stop();
    if (options.verbose) { std::cout << time << std::endl; }
};

} } }

#endif