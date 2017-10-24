#ifndef OMI_UTILITY_STOPWATCH_HPP_
#define OMI_UTILITY_STOPWATCH_HPP_

#include <chrono>
#include <string>

// Stopwatch

namespace omi {

struct stopwatch {

  //// Member Variables ///////////

    std::chrono::time_point<std::chrono::high_resolution_clock> begin;     // Start time in seconds
    std::chrono::time_point<std::chrono::high_resolution_clock> end;       // Endtime in seconds
    std::string name { "Time: " };                                         // Title for display

  //// Construction ///////////////

    // TODO: start bool for printing?
    // TODO: make an autotimer that starts on construction

    // Default constructor 
    stopwatch() {}

  //// Implementation /////////////

    // Start timer
    void start() {
        begin = std::chrono::high_resolution_clock::now();
    }

    // Stop timer
    void stop() {
        end = std::chrono::high_resolution_clock::now();
    }

    // Return elapsed seconds
    double seconds() const {
        return std::chrono::duration<double>(end - begin).count();
    }
};

// Stream operator
inline std::ostream &operator<<(std::ostream &out, const stopwatch &watch) {
    return out << watch.name << std::endl
               << "  " << watch.seconds() << std::endl;
}

}

#endif