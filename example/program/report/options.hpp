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

  //// Interface ////////////////

    static options parse(int argc, char *argv[]) {
        // Delcare options
        boost::program_options::options_description description("Omi Latency Report Options: ");
        description.add_options()
            ("help", "Help")                     // automatic?
            ("verbose", "Enable verbose output") // automatic?
            (inbound::file::option, boost::program_options::value<std::string>(), inbound::file::note)
            (outbound::file::option, boost::program_options::value<std::string>(), outbound::file::note)
            (report::file::option, boost::program_options::value<std::string>(), report::file::note);
        auto arg = omi::program::options(argc, argv, description);

        // Parse Options
        options options; // TODO: use constructor, add ini intialization
          options.path = arg.required<std::string>(report::file::option);
          options.report.title = arg.conditional<std::string>(html::title::option, "Omi");
          options.report.header = arg.conditional<std::string>(html::header::option, "Omi Latency Lab");
          options.report.copyright = arg.conditional<std::string>(html::copyright::option, "OMI. All rights reserved."); ;
          options.files.inbound = arg.required<std::string>(inbound::file::option);
          options.files.outbound = arg.required<std::string>(outbound::file::option);
          options.verbose = arg.verbose();

        return options;
    }
};

#endif
