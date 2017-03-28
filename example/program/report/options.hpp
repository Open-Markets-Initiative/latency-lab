#ifndef OMI_EXAMPLE_REPORT_OPTIONS_HPP
#define OMI_EXAMPLE_REPORT_OPTIONS_HPP

#include <example/program/report/args.hpp>
#include <omi/latency/options.hpp>

// Example report options

struct input {
    std::string inbound;
    std::string outbound;
};

struct options {
    omi::latency::report::options report;
    input file;
    bool verbose;
};

inline options parse(int argc, char *argv[]) {
    auto arg = args(argc, argv);

    options options;
      options.report.path = arg.conditional(report::file::option, "todo"); // add required
      options.report.title = "Omi";
      options.report.header = "Latency Example Run";
      options.report.copyright = "OMI. All rights reserved.";
      options.file.inbound = arg.conditional(inbound::file::option, "todo");
      options.file.outbound = arg.conditional(outbound::file::option, "todo");
      options.verbose = arg.verbose();

    return options;
}


#endif
