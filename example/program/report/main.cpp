#include <omi/wireshark/matcher.hpp>
#include <omi/latency/report.hpp>

#include <example/program/report/options.hpp>
#include <example/events/inbound.hpp>
#include <example/events/outbound.hpp>

// Generate an example wireshark latency report

int main(int argc, char *argv[]) {
    using matcher = omi::wireshark::matcher<example::inbound, example::outbound>;

    try {
        auto options = options::parse(argc, argv);
        if (options.verbose) { std::cout << "Generate Example Html Report" << std::endl; }

        // Match events
        const auto wireshark = matcher{ options.files };

        // Generate report
        omi::latency::report report;
          report.layout = options.report;
          report.files = options.files;
          report.data = wireshark.events.deltas().values(); // Need to make this better
        report.write(options.path);

    } catch (std::exception &exception) {
        std::cerr << "Error: " << exception.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "Unknown exception" << std::endl;
        return 1;
    }
}
