#ifndef OMI_UTILITY_TIMER_HPP_
#define OMI_UTILITY_TIMER_HPP_

#include <chrono>
#include <string>

// Timer

namespace omi {
namespace utility {

struct timer {
    using Seconds = double;

    // Memeber Variables
    std::chrono::time_point<std::chrono::high_resolution_clock> begin;                 // Runtime in seconds
    std::chrono::time_point<std::chrono::high_resolution_clock> end;                   // Runtime in seconds
    std::string name { "Time: " };        // Title for display

    // TODO: add a start bool for printing



    // Default constructor 
    Timer() {}

    // TODO: make an autotimer in the future
    // (start on construction sample time when time is called)

  // Implementation
    void start() {
        begin = std::chrono::high_resolution_clock::now();
    }

    void stop() {
        end = std::chrono::high_resolution_clock::now();
    }

    // seconds
    double seconds() const {
        return std::chrono::duration <Seconds>(end - begin).count();
    }
};

// Stream operator
inline std::ostream &operator<<(std::ostream &out, const timer &timer) {
    return out << timer.name << std::endl
               << "  " << timer.seconds() << std::endl;
}

} }

#endif // OMI_UTILITY_TIMER_HPP_
