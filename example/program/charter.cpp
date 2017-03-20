#include <boost/program_options.hpp>

#include <omi/wireshark/matcher.hpp>
#include <omi/wireshark/report.hpp>

#include <example/program/args.hpp>
#include <example/events/inbound.hpp>
#include <example/events/outbound.hpp>

// Generate an example wireshark latency report

int main(int argc, char *argv[]) {
    using matcher = omi::wireshark::matcher<example::inbound, example::outbound>;

    try {
        // Supported program options
        boost::program_options::options_description description("Omi Analyzer Options: ");
        description.add_options()
          ("help", "Help")
          ("verbose", "Enable verbose output")
          (inbound::file::option, boost::program_options::value<std::string>(), inbound::file::note)
          (outbound::file::option, boost::program_options::value<std::string>(), outbound::file::note)
          (report::file::option, boost::program_options::value<std::string>(), report::file::note);

        boost::program_options::variables_map values;

        auto parse = boost::program_options::parse_command_line(argc, argv, description);
        boost::program_options::store(parse, values);
        boost::program_options::notify(values);

        // Check to print help
        if (values.count("help") != 0) {
            std::cout << description << std::endl; exit(1);
        }
    
        // Check if min number of values are valid?   
        if (values.count(inbound::file::option) == 0) {
            std::cout << "Usage: " << std::endl; exit(1);
        }
        auto inbounds = values[inbound::file::option].as<std::string>();

        // Check if min number of values are valid?   
        if (values.count(outbound::file::option) == 0) {
            std::cout << "Usage: " << std::endl; exit(1);
        }
        auto outbounds = values[outbound::file::option].as<std::string>();

        if (values.count("verbose") != 0) {
            std::cout << "Generate Example Html Report" << std::endl;
        }

        // Match files
        const auto wireshark = matcher{ inbounds, outbounds };

        // Write chart file
        if (values.count(report::file::option) != 0) {
            omi::html::report::options options;
              options.path = values[report::file::option].as<std::string>();
              options.title = "Omi";
              options.header = "Latency Example Run";
              options.copyright = "OMI. All rights reserved.";

            omi::html::report::data data;
              data.values = wireshark.events.deltas().values();

            omi::html::report::write(options, data);
        }

    } catch (std::exception &exception) {
        std::cerr << "Error: " << exception.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "Unknown exception" << std::endl;
        return 1;
    }
}
