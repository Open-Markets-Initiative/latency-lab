#ifndef OMI_EVENT_MATCH_HPP_
#define OMI_EVENT_MATCH_HPP_

#include <omi/analysis/delta.hpp>

// Matched events 

namespace omi {
namespace event {

template <class inbound, class outbound>
struct match {
  // TODO: Add static assert on types

  //// Member Variables ///////////

    inbound trigger;                  // Inbound trigger event
    outbound response;                // Outbound response event

  //// Construction ///////////////

    // Standard constructor
    match(const inbound &trigger, const outbound &response)
      : trigger{ trigger }, response{ response } {}

  //// Interface ///////////////

    // Return identifier
    typename inbound::identifier id() const {
        return trigger.id();
    }

    // Return time delta
    double delta() const { // need to make this professional
        return (response.time().nanoseconds() - trigger.time().nanoseconds()) / 1000.;
    }

    // Todo: Make an info version
};

// Stream operator
template <class inbound, class outbound>
std::ostream &operator<<(std::ostream &out, const match<inbound, outbound> &match) {
    return out;  //TODO: out << match.inbound << " | " << match.outbound;
}

} }

#endif
