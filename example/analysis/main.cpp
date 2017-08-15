#include <example/analysis/records/inbound.hpp>
#include <example/analysis/records/outbound.hpp>
#include <omi/latency/analysis.hpp>

// Generate an example wireshark matching report

int main(int argc, char *argv[]) {
    try {
        omi::latency::analysis::of<example::inbound, example::outbound>(argc, argv);
    } catch (std::exception &exception) {
        std::cerr << "Error: " << exception.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "Unknown exception" << std::endl;
        return 1;
    }
}