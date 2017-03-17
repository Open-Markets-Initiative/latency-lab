#ifndef OMI_UTILITY_PROGRAM_OPTIONS_HPP_
#define OMI_UTILITY_PROGRAM_OPTIONS_HPP_
#pragma once

#include <boost/program_options.hpp>

#include <iostream>

    // Wrapper for boost program options

namespace omi { namespace program {

// Common program options
namespace help    { static constexpr const char * option = "help";}
namespace help    { static constexpr const char * note = "Program Manual"; }
namespace verbose { static constexpr const char * option = "verbose"; }
namespace verbose { static constexpr const char * note = "Print verbose logging"; }

struct options { // should be a class

    boost::program_options::variables_map values;

    // Standard constructor
    options(int argc, char *argv[], boost::program_options::options_description description) {
        namespace po = boost::program_options;

        // Automatically add help/verbose

        po::store(po::parse_command_line(argc, argv, description), values);
        po::notify(values);

        // Check to print help
        if (has(help::option)) {
            std::cout << description << std::endl;
            exit(1);
        }
    }

    // Interface for options
    bool get(const std::string &option) const { // is this used?
        return has(option);
    }

    // Return option or default value
    std::string get(const std::string &option, const std::string &value) const {
        return has(option) ? values[option].as<std::string>().c_str() : value;
    }

  /////////////////////////////////

    // Is option a program variable?
    bool has(const std::string &option) const {
        return values.count(option) != 0;
    }

  /////////////////////////////////

    // Is verbose?
    bool verbose() const {
        return has(verbose::option);
    }
};

} }

#endif // OMI_UTILITY_PROGRAM_OPTIONS_HPP_
