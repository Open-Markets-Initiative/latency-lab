#include <omi/latency/email.hpp>

#include "cme/fix.hpp"
#include "cme/sbe.hpp"

// Generate an emailable latency report for cme tick to trade

int main(int argc, char *argv[]) {
    try {
        omi::latency::email::of<cme::sbe, cme::fix>(argc, argv);
    } catch (std::exception &exception) {
        std::cerr << "Error: " << exception.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "Unknown exception" << std::endl;
        return 1;
    }
}
