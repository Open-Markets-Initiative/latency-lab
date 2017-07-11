#ifndef OMI_LATENCY_COMPARISON_OPTIONS_HPP_
#define OMI_LATENCY_COMPARISON_OPTIONS_HPP_

#include <omi/program/options.hpp>
#include <omi/program/settings.hpp>
#include <omi/latency/args.hpp>
#include <omi/latency/comparison/configuration.hpp>

//  Options for omi html latency comparison (multiple run)

namespace omi { 
namespace latency {
namespace comparison {

struct options {

  //// Member Variables ///////////

    comparison::configuration report;  // Latency comparison report options
    std::string directory;             // Directory of events files (for comparison)
    std::string path;                  // Html report output path
    bool verbose;                      // Print status to standard out

  //// Construction //////////////

    // Construct options from args or ini file
    template<class setting>
    explicit options(const setting &option, bool verbose) : verbose{ verbose }  {
        directory = option.template required<std::string>(::events::directory::option);
        path = option.template required<std::string>(::html::report::option);
        report.title = option.template conditional<std::string>(::html::title::option, "Omi");
        report.header = option.template conditional<std::string>(::html::header::option, "Omi Latency Lab");
        report.copyright = option.template conditional<std::string>(::html::copyright::option, "OMI. All rights reserved.");
    }

  //// Interface ////////////////

    // Parse program args into options
    static options parse(int argc, char *argv[], std::string title = "Latency Comparison Report") {
        // Declare options
        boost::program_options::options_description description(title);
        description.add_options()
            (::ini::file::option, boost::program_options::value<std::string>(), ::ini::file::note)
            (::events::directory::option, boost::program_options::value<std::string>(), ::events::directory::note)
            (::html::title::option, boost::program_options::value<std::string>(), ::html::title::note)
            (::html::header::option, boost::program_options::value<std::string>(), ::html::header::note)
            (::html::copyright::option, boost::program_options::value<std::string>(), ::html::copyright::note)
            (::html::report::option, boost::program_options::value<std::string>(), ::html::report::note);

        // If ini file exists, read options from file
        auto args = omi::program::options(argc, argv, description);
        if (args.exists(ini::file::option)) {
            auto ini = omi::program::settings{ args.required<std::string>(ini::file::option) };
            return options{ ini.section("comparison"), args.verbose() }; // How to make this seamless?
        }

        // Otherwise initialize from program args
        return options{ args, args.verbose() };
    }
};

} } }

#endif