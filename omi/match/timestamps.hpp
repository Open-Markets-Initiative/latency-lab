#ifndef OMI_MATCH_TIMESTAMPS_HPP_
#define OMI_MATCH_TIMESTAMPS_HPP_

#include <ostream>

// Matched event timestamp

namespace omi {
namespace match {

template <class inbound, class outbound = inbound>
struct timestamps {

  //// Member Variables ///////////

    inbound trigger;
    outbound response;

  //// Construction ///////////////

    // Standard constructor
    timestamps(const inbound &trigger, outbound &response)
      : trigger{ trigger }, response{ response } {}

};

// Stream operator
template<class inbound, class outbound>
std::ostream &operator<<(std::ostream &out, const timestamps<inbound, outbound> &time) {
    return out << time.trigger << "," << time.response;
}

} }

#endif