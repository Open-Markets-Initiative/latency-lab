#include <omi/latency/report.hpp>

#include "cme/fix.hpp"
#include "cme/sbe.hpp"

// Generate a html wireshark latency report

int main(int argc, char *argv[]) {
    try {
        omi::latency::report::of<cme::sbe, cme::fix>(argc, argv);
    } catch (std::exception &exception) {
        std::cerr << "Error: " << exception.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "Unknown exception" << std::endl;
        return 1;
    }
}
