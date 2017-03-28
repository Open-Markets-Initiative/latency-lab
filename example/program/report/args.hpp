#ifndef OMI_EXAMPLE_REPORT_ARGS_HPP
#define OMI_EXAMPLE_REPORT_ARGS_HPP

#include <omi/program/options.hpp>
#include <example/program/args.hpp>

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

#endif