#ifndef OMI_ANALYSIS_DELTA_HPP_
#define OMI_ANALYSIS_DELTA_HPP_

#include <algorithm>
#include <ostream>
#include <cmath>

// Time delta

namespace omi {
namespace analysis {

struct delta {

  //// Member Variables ///////////

    double initial;        // Start timestamp 
    double value;          // Delta time value

  //// Construction ///////////////

    // Default constructor
    delta() 
      : initial{ 0. }, value{ 0 } {}

    // Standard constructor
    delta(double one, double two)
        : initial{ std::min(one, two) }, value{ std::abs(one - two) }
    {}
};

// Stream operator
inline std::ostream &operator<<(std::ostream &out, const delta &delta) {
    return out << delta.initial << ":" << delta.value; // TODO: use fixed precision here
}

} }

#endif