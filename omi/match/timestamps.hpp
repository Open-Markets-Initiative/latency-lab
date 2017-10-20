#ifndef OMI_MATCH_TIMESTAMPS_HPP_
#define OMI_MATCH_TIMESTAMPS_HPP_

#include <ostream>

// Matched event timestamp

namespace omi {
namespace match {

template <typename inbound, typename outbound = inbound>
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
template<typename inbound, typename outbound>
std::ostream &operator<<(std::ostream &out, const timestamps<inbound, outbound> &time) {
    return out << time.trigger << "," << time.response;
}

} }

#endif