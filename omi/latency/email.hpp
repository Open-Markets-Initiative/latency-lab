#ifndef OMI_LATENCY_EMAIL_HPP_
#define OMI_LATENCY_EMAIL_HPP_

#include <omi/latency/process/run.hpp>
#include <omi/latency/email/options.hpp>
#include <omi/latency/email/components.hpp>

// Single run omi html only latency report generation

namespace omi {
namespace latency {
namespace email {

// Email program defaults 
struct defaults {
    static constexpr const char * title = "Generate Emailable Latency Report";
    static constexpr const char * inbound = "events";
    static constexpr const char * outbound = "responses";
};

// Latency email program template
template <class inbound, class outbound, class descriptions = defaults>
void of(int argc, char *argv[]) {
    // Parse program options for settings
    auto options = options::parse(argc, argv);

    // Load and match events
    auto result = process::run<inbound, outbound, descriptions>(options.files, options.verbose);

    // Configure email report
    if (options.verbose) { std::cout << "Generating Html Latency Report Email" << std::endl; }
    components email;
      email.layout = options.email;
      email.files = options.files;
      email.data = result.deltas(options.email.period);

    // Write email
    email.write(options.path);

    // Program information
    if (options.verbose) { std::cout << options << std::endl; }
};

} } }

#endif