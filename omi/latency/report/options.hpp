#ifndef OMI_LATENCY_REPORT_OPTIONS_HPP_
#define OMI_LATENCY_REPORT_OPTIONS_HPP_

#include <omi/program/options.hpp>
#include <omi/wireshark/options.hpp>
#include <omi/latency/args.hpp>
#include <omi/latency/report/configuration.hpp>

//  Options for omi single run html latency report

namespace omi { 
namespace latency {
namespace report {

// Html report settings/options
struct options {

  //// Member Variables ///////////

    report::configuration report;  // Html report options
    wireshark::inputs files;       // Match Input files
    std::string path;              // Output path
    bool verbose;                  // Verbose

  //// Construction //////////////

    // Construct
    explicit options(const omi::program::options &option) {
        path = option.required<std::string>(path::report::option);
        report.title = option.conditional<std::string>(::html::title::option, "Omi");
        report.header = option.conditional<std::string>(::html::header::option, "Omi Latency Lab");
        report.copyright = option.conditional<std::string>(::html::copyright::option, "OMI. All rights reserved.");
        files.inbound = option.required<std::string>(::inbound::file::option);
        files.outbound = option.required<std::string>(::outbound::file::option);
        verbose = option.verbose();
    }

  //// Interface ////////////////

    // Parse program args into options
    static options parse(int argc, char *argv[]) {
        // Delcare options
        boost::program_options::options_description description("Omi Latency Report Options: ");
        description.add_options()
            (inbound::file::option, boost::program_options::value<std::string>(), inbound::file::note)
            (outbound::file::option, boost::program_options::value<std::string>(), outbound::file::note)
            (path::report::option, boost::program_options::value<std::string>(), path::report::note);
        auto args = omi::program::options(argc, argv, description);

        // TODO: make a version that takes ini
        return options{ args };
    }
};

} } }

#endif