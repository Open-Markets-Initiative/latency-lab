#ifndef OMI_EXAMPLE_REPORT_OPTIONS_HPP
#define OMI_EXAMPLE_REPORT_OPTIONS_HPP

#include <omi/latency/options.hpp>
#include <omi/wireshark/options.hpp>
#include <omi/program/options.hpp>

#include <example/program/args.hpp>

// Example html report options
struct options {

  //// Member Variables ///////////

    omi::latency::options report;
    omi::wireshark::inputs files;
    std::string path;             // Output path
    bool verbose;                 // Verbose

  //// Construction //////////////

    // Construct
    explicit options(const omi::program::options &option) {
        path = option.required<std::string>(report::file::option);
        report.title = option.conditional<std::string>(html::title::option, "Omi");
        report.header = option.conditional<std::string>(html::header::option, "Omi Latency Lab");
        report.copyright = option.conditional<std::string>(html::copyright::option, "OMI. All rights reserved."); ;
        files.inbound = option.required<std::string>(inbound::file::option);
        files.outbound = option.required<std::string>(outbound::file::option);
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
            (report::file::option, boost::program_options::value<std::string>(), report::file::note);
        auto arg = omi::program::options(argc, argv, description);

        // TODO: make a version that takes ini
        return options{ arg };
    }
};

#endif
