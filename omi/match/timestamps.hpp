#ifndef OMI_MATCH_TIMESTAMPS_HPP_
#define OMI_MATCH_TIMESTAMPS_HPP_

#include <ostream>

// Matched event timestamp

namespace omi {
namespace match {

template <typename inbound, typename outbound>
struct timestamps {

    // Probably need a static assert for - existence

  //// Member Variables ///////////

    decltype(std::declval<inbound>().time()) trigger;
    decltype(std::declval<outbound>().time()) response;

  //// Construction ///////////////

    // Default constructor
    timestamps() = default;

    // Standard constructor
    timestamps(const inbound &in, const outbound &out)
      : trigger{ in.time() }, response{ out.time() } {}

  //// Methods ////////////////////

    // Change in time
    auto delta() const {
        return response - trigger;
    }
};

// Stream operator
template<typename inbound, typename outbound>
std::ostream &operator<<(std::ostream &out, const timestamps<inbound, outbound> &time) {
    return out << time.trigger << "," << time.response, time.delta();
}

} }

#endif