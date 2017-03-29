#include <omi/wireshark/matcher.hpp>
#include <omi/latency/report.hpp>

#include <example/program/report/options.hpp>
#include <example/events/inbound.hpp>
#include <example/events/outbound.hpp>

// Generate an example wireshark latency report

int main(int argc, char *argv[]) {
    using matcher = omi::wireshark::matcher<example::inbound, example::outbound>;

    try {
        auto options = parse(argc, argv);

        if (options.verbose) { // How to handle this best?
            std::cout << "Generate Example Html Report" << std::endl;
        }

        // Match files
        const auto wireshark = matcher{ options.files };
        omi::latency::report::data data;
           data.values = wireshark.events.deltas().values();

        omi::latency::report::write(options.report, data);
    } catch (std::exception &exception) {
        std::cerr << "Error: " << exception.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "Unknown exception" << std::endl;
        return 1;
    }
}
