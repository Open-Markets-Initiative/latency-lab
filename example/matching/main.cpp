#include <example/matching/events/inbound.hpp>
#include <example/matching/events/outbound.hpp>
#include <omi/latency/matching.hpp>

// Generate an example wireshark matches list

int main(int argc, char *argv[]) {
    try {
        omi::latency::matching::of<example::inbound, example::outbound>(argc, argv);
    } catch (std::exception &exception) {
        std::cerr << "Error: " << exception.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "Unknown exception" << std::endl;
        return 1;
    }
}