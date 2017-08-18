#ifndef OMI_EVENT_MATCH_HPP_
#define OMI_EVENT_MATCH_HPP_

#include <omi/analysis/delta.hpp>
#include <omi/match/info.hpp>
#include <omi/match/timestamps.hpp>
#include <omi/event/asserts.hpp>

// Matched events 

namespace omi {
namespace event {

// Event match
template <class inbound, class outbound>
struct match {
    // Verify record id compatibility
    static_assert(is_matchable<inbound, outbound>, "Inbound and outbound records must use the same id() type");

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
        return omi::match::timestamps<decltype(std::declval<inbound>().timestamp()),
            decltype(std::declval<outbound>().timestamp())>{trigger.time(), response.time()};
    }

  // TODO: remove this

    // Return match time delta in microseconds
    auto delta() const { // Need to make this professional/general
        return response.time().microseconds() - trigger.time().microseconds();
    }
};

// Stream operator
template <class inbound, class outbound>
std::ostream &operator<<(std::ostream &out, const match<inbound, outbound> &match) {
    return out; // TODO: << match.trigger << " | " << match.response; requires stream operator
}

} }

#endif