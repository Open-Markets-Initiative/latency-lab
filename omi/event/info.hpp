#ifndef OMI_EVENT_INFO_HPP_
#define OMI_EVENT_INFO_HPP_

#include <omi/event/asserts.hpp>

#include <ostream>

// Matched event info

namespace omi {
namespace event {

template <class inbound, class outbound>
struct info {

    // Verify record id compatibility
    static_assert(is_matchable<inbound, outbound>, "Inbound and outbound records must use the same id() type");

  //// Member Variables ///////////

    decltype(std::declval<outbound>().id()) id;
    decltype(std::declval<inbound>().info()) trigger;
    decltype(std::declval<outbound>().info()) response;

  //// Construction ///////////////

    // Standard constructor
    info(const inbound &in, const outbound &out)
      : id{ in.id() }, trigger{ in.info() }, response{ out.info() } {}

    // TODO: add times

};

// Stream operator
template <class inbound, class outbound>
std::ostream &operator<<(std::ostream &out, const info<inbound, outbound> &info) {
    return out << info.trigger << " [ " << info.id << " ] " << info.trigger;
}

} }

#endif