#ifndef OMI_EVENT_MATCH_HPP_
#define OMI_EVENT_MATCH_HPP_

#include <omi/match/info.hpp>
#include <omi/match/timestamps.hpp>
#include <omi/event/asserts.hpp>

// Matched events 

namespace omi {
namespace event {

// Event match
template <typename inbound, typename outbound>
struct match {
    // Verify record id compatibility
    static_assert(is_matchable<inbound, outbound>, "Inbound and outbound records must use the same id() type");

    // TODO: add some traits

  //// Member Variables ///////////

    inbound trigger;                  // Inbound trigger event
    outbound response;                // Outbound response event

  //// Construction ///////////////

    // Standard constructor
    match(const inbound &trigger, const outbound &response)
      : trigger{ trigger }, response{ response } {}

  //// Methods ////////////////////

    // Return match identifier
    auto id() const {
        return trigger.id();
    }

    // Return match info
    auto info() const {
        return omi::match::info<inbound, outbound>{trigger, response};
    }

    // Return match timestamps
    auto timestamps() const {
        return omi::match::timestamps<inbound, outbound>{trigger, response};
    }

};

// Stream operator
template <typename inbound, typename  outbound>
std::ostream &operator<<(std::ostream &out, const match<inbound, outbound> &match) {
    return out; // TODO: << match.trigger << " | " << match.response; requires stream operator
}

} }

#endif