#ifndef OMI_ANALYSIS_DELTA_HPP_
#define OMI_ANALYSIS_DELTA_HPP_

#include <algorithm>
#include <ostream>

// Delta

namespace omi {
namespace analysis {

struct delta {

  //// Member Variables ///////////

    double initial;        // Start timestamp 
    double value;          // Delta time value
    size_t precision;      // Seconds decimal precision

  //// Construction ///////////////

    // Default constructor
    delta() 
      : initial{ 0. }, value{ 0 }, precision{ 0 } {}

    // Standard constructor with precision
    delta(double one, double two, size_t precision)
      : initial{ std::min(one, two) }, value{ std::abs(one - two) }, precision{ precision }
    {}

    // tshark constructor (calculates delta from 2 timestamps)
    delta(double one, double two)
        : initial{ std::min(one, two) }, value{ std::abs(one - two) }, precision{ 9 }
    {}
};

// Stream operator
inline std::ostream &operator<<(std::ostream &out, const delta &delta) {
    return out << delta.initial << ":" << delta.value; // TODO: use precision here
}

} }

#endif
