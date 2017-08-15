#ifndef OMI_PROGRAM_OPTIONS_HPP_
#define OMI_PROGRAM_OPTIONS_HPP_

#include <boost/program_options.hpp>

#include <iostream>
#include <iso646.h>

// Omi program options

namespace omi {
namespace program {

// Common program options
namespace help    { static constexpr const char* option = "help";}
namespace help    { static constexpr const char* note = "Program Usage"; }
namespace verbose { static constexpr const char* option = "verbose"; }
namespace verbose { static constexpr const char* note = "Verbose Output"; }

struct options {

  //// Member Variables ///////////

    boost::program_options::variables_map values;

  //// Construction ///////////////

    // Standard constructor
    options(int argc, char *argv[], boost::program_options::options_description description) {
        // Automatically add help and verbose options
        description.add_options()
            (help::option, help::note)
            (verbose::option, verbose::note);

        // Parse command line
        auto parse = boost::program_options::parse_command_line(argc, argv, description);
        boost::program_options::store(parse, values);
        boost::program_options::notify(values);

        // Check to print help
        if (exists(help::option)) {
            std::cout << description << std::endl;
            exit(1);
        }
    }

  //// Methods ////////////////////

    // Returns value if it exists, otherwise default value 
    template<typename T>
    T conditional(const std::string arg, const T &value) const {
        return exists(arg) ? values[arg].as<T>() : value;
    }

/*
    // Convenience method for setting optional value only if setting exists
    template<typename T>
    boost::optional<T> optional(const std::string arg) const {
        return exists(arg) ? values[arg].as<T>() : T;
    }
*/
    // Returns program argument, throws exception if required arg is missing
    template<typename T>
    T required(const std::string arg) const {
        // Verify required field exists
        if (not exists(arg)) {
            throw std::invalid_argument("Missing required program option: " + arg);
        }

        return values[arg].as<T>();
    }

  /////////////////////////////////

    // Does option exist?
    bool exists(const std::string &option) const {
        return values.count(option) != 0;
    }

  /////////////////////////////////

    // Is verbose?
    bool verbose() const {
        return exists(verbose::option);
    }
};

} }

#endif