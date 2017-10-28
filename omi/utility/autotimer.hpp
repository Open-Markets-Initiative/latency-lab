#ifndef OMI_UTILITY_AUTOTIMER_HPP_
#define OMI_UTILITY_AUTOTIMER_HPP_

#include <chrono>
#include <string>

// Auto timer

namespace omi {

struct autotimer {
    using time = std::chrono::time_point<std::chrono::high_resolution_clock>;

  //// Member Variables ///////////

    time begin;                            // Start time
    std::string name { "Elapsed Time: " }; // Title for display

  //// Construction ///////////////

    // Default constructor 
    autotimer() : begin{ now() } {}

  //// Methods ////////////////////

    // Return elapsed seconds
    double seconds() const {
        return std::chrono::duration<double>(now() - begin).count();
    }

  /////////////////////////////////

    // Return current time
    static time now() {
        return std::chrono::high_resolution_clock::now();
    }

    // Return elapsed seconds
    double static seconds(const time start, const time finish) {
        return std::chrono::duration<double>(finish - start).count();
    }
};

// Stream operator
inline std::ostream &operator<<(std::ostream &out, const autotimer &timer) {
    return out << timer.name << std::endl
               << "  " << timer.seconds() << std::endl;
}

}

#endif