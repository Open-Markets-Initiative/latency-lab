#include <example/events/inbound.hpp>
#include <example/events/outbound.hpp>
#include <omi/latency/comparison.hpp>

// Generate an example wireshark latency comparison report

int main(int argc, char *argv[]) {
    try {
        omi::latency::comparison::of<example::inbound, example::outbound>(argc, argv);
    } catch (std::exception &exception) {
        std::cerr << "Error: " << exception.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "Unknown exception" << std::endl;
        return 1;
    }
}
