#ifndef OMI_WIRESHARK_MATCH_HPP_
#define OMI_WIRESHARK_MATCH_HPP_

#include <omi/wireshark/event.hpp>

#include <iostream>

// Matched events 

namespace omi { 
namespace wireshark {

struct match { // template on event...remove id

  //// Member Variables ///////////

    frame inbound;                 // Inbound trigger event wireshark frame 
    frame outbound;                // Triggered outbound 
    event::id id;                  // Event id

  //// Construction ///////////////

    // Standard constructor
    match(const event &inbound, const event &outbound)
      : inbound{ inbound.frame }, outbound{ outbound.frame }, id{ inbound.identifier } {}
};

// Stream operator
inline std::ostream &operator<<(std::ostream &out, const match &match) {
    return out << match.inbound << "," << match.outbound << "," << match.id;
}

} }

#endif
