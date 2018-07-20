#ifndef OMI_MATCH_INFO_HPP_
#define OMI_MATCH_INFO_HPP_

#include <ostream>

#include <omi/event/asserts.hpp>

// Matched event info

namespace omi::match {

template <typename inbound, typename outbound>
struct info {

    // Verify record id compatibility
    static_assert(event::is_matchable<inbound, outbound>, "Inbound and outbound records must use the same id() type");

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
template <typename inbound, typename outbound>
std::ostream &operator<<(std::ostream &out, const info<inbound, outbound> &info) {
    return out << info.trigger << " [" << info.id << "] " << info.response;
}

///////////////////////////////////////////////

template <typename inbound, typename outbound>
using infos = std::vector<match::info<inbound, outbound>>;

// Stream operator
template <typename inbound, typename outbound>
std::ostream &operator<<(std::ostream &out, const infos<inbound, outbound> &infos) {
    for (const auto &info : infos) {
        out << info << std::endl;
    }

    return out;
}

}

#endif