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

    // Calculate time delta
    analysis::delta delta() const {
        return analysis::delta{trigger.microseconds(), response.microseconds()};
    }

    // Return identifier
    typename inbound::identifier id() const {
        return trigger.id();
    }

    // Return time // need new name
    double time() const {
        return std::abs( trigger.microseconds() - response.microseconds());
    }
};

// Stream operator
template <class inbound, class outbound>
std::ostream &operator<<(std::ostream &out, const match<inbound, outbound> &match) {
    return out;  //TODO: out << match.inbound << " | " << match.outbound;
}

} }

#endif
