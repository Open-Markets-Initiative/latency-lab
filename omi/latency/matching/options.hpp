#ifndef OMI_LATENCY_MATCHING_OPTIONS_HPP_
#define OMI_LATENCY_MATCHING_OPTIONS_HPP_

#include <omi/program/options.hpp>
#include <omi/program/settings.hpp>
#include <omi/latency/args.hpp>
#include <omi/match/inputs.hpp>

//  Options for omi latency matching

namespace omi { 
namespace latency {
namespace matching {

struct options {

  //// Member Variables ///////////

    match::inputs files;           // Event input files
    std::string path;              // Matches list output path
    bool verbose;                  // Print status to standard out

  //// Construction //////////////

    // Construct options from args or ini file
    template<typename setting>
    explicit options(const setting &option, bool verbose) : verbose{ verbose }  {
        files.inbound = option.template required<std::string>(::inbound::file::option);
        files.outbound = option.template required<std::string>(::outbound::file::option);
        path = option.template required<std::string>(::matching::file::option);
    }

  //// Interface ////////////////

    // Parse program args into options
    static options parse(int argc, char *argv[], const std::string title = "Matching Details") {
        // Declare options
        boost::program_options::options_description description(title);
        description.add_options()
            (::inbound::file::option, boost::program_options::value<std::string>(), ::inbound::file::note)
            (::outbound::file::option, boost::program_options::value<std::string>(), ::outbound::file::note)
            (::matching::file::option, boost::program_options::value<std::string>(), ::matching::file::note);

        // If ini file exists, read options from file
        auto args = omi::program::options(argc, argv, description);

        // Otherwise initialize from program args
        return options{ args, args.verbose() };
    }
};

} } }

#endif