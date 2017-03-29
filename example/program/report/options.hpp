#ifndef OMI_EXAMPLE_REPORT_OPTIONS_HPP
#define OMI_EXAMPLE_REPORT_OPTIONS_HPP

#include <omi/latency/options.hpp>
#include <omi/wireshark/options.hpp>
#include <omi/program/options.hpp>

#include <example/program/args.hpp>

// Example report options
struct options {
    omi::latency::report::options report;
    omi::wireshark::inputs files;
    bool verbose;
};

// Supported program options
inline omi::program::options args(int argc, char *argv[]) {
    boost::program_options::options_description description("Omi Latency Report Options: ");
    description.add_options()
        ("help", "Help")                     // automatic?
        ("verbose", "Enable verbose output") // automatic?
        (inbound::file::option, boost::program_options::value<std::string>(), inbound::file::note)
        (outbound::file::option, boost::program_options::value<std::string>(), outbound::file::note)
        (report::file::option, boost::program_options::value<std::string>(), report::file::note);

    return omi::program::options(argc, argv, description);
}

inline options parse(int argc, char *argv[]) {
    auto arg = args(argc, argv);

    options options;
      options.report.path = arg.conditional(report::file::option, "todo"); // add required
      options.report.title = "Omi";
      options.report.header = "Latency Example Run";
      options.report.copyright = "OMI. All rights reserved.";
      options.files.inbound = arg.conditional(inbound::file::option, "todo");
      options.files.outbound = arg.conditional(outbound::file::option, "todo");
      options.verbose = arg.verbose();

    return options;
}


#endif
