#include <example/program/args.hpp>
#include <example/events/inbound.hpp>
#include <example/events/outbound.hpp>

#include <omi/wireshark/matcher.hpp>
#include <boost/program_options.hpp>

// Generate an example report

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
          (matching::file::option, boost::program_options::value<std::string>(), matching::file::note);

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
            std::cout << "Omi Example Matching Results" << std::endl;
        }

        // Match events
        auto wireshark = matcher{ inbounds, outbounds };
        if (values.count("verbose") != 0) { std::cout << wireshark; }

        // Writes matches file
        if (values.count(matching::file::option) != 0) {
            auto file = values[matching::file::option].as<std::string>();
            wireshark.events.matches.write(file);
        }
    } catch (std::exception &exception) {
        std::cerr << "Error: " << exception.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "Unknown exception" << std::endl;
        return 1;
    }

    return 0;
}
