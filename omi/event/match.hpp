#ifndef OMI_EVENT_MATCH_HPP_
#define OMI_EVENT_MATCH_HPP_

#include <omi/analysis/delta.hpp>
#include <omi/event/info.hpp>
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

    // Return time delta
    double delta() const { // need to make this professional
        return (response.time().nanoseconds() - trigger.time().nanoseconds()) / 1000.;
    }

    // Todo: Make an info 
    auto info() const {
        return event::info<inbound, outbound>{trigger, response};
    }
};

// Stream operator
template <class inbound, class outbound>
std::ostream &operator<<(std::ostream &out, const match<inbound, outbound> &match) {
    return out; // TODO: << match.trigger << " | " << match.response;
}

} }

#endif