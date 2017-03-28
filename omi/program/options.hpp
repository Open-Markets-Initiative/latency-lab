#ifndef OMI_PROGRAM_OPTIONS_HPP_
#define OMI_PROGRAM_OPTIONS_HPP_

#include <boost/program_options.hpp>

#include <iostream>

// Fluent wrapper for boost program options

namespace omi {
namespace program {

// Common program options
namespace help    { static constexpr const char* option = "help";}
namespace help    { static constexpr const char* note = "Program Usage"; }
namespace verbose { static constexpr const char* option = "verbose"; }
namespace verbose { static constexpr const char* note = "Verbose Output"; }

struct options { // should be a class

    boost::program_options::variables_map values;

    // Standard constructor
    options(int argc, char *argv[], boost::program_options::options_description description) {

        // TODO: Automatically add help/verbose

        auto parse = boost::program_options::parse_command_line(argc, argv, description);
        boost::program_options::store(parse, values);
        boost::program_options::notify(values);

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
    std::string conditional(const std::string &option, const std::string &value) const {
        return has(option) ? values[option].as<std::string>().c_str() : value;
    }

    // add require...

  /////////////////////////////////

    // Is option in args?
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

#endif
