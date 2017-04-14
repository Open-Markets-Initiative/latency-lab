#ifndef OMI_EVENT_MATCH_HPP_
#define OMI_EVENT_MATCH_HPP_

#include <iostream>

// Matched events 

namespace omi {
namespace event {

template <class trigger, class response>
struct match {

  //// Member Variables ///////////

	trigger inbound;                  // Inbound trigger event
	response outbound;                // Outbound response event

  //// Construction ///////////////

    // Standard constructor
    match(const trigger &inbound, const response &outbound)
      : inbound{ inbound }, outbound{ outbound } {}
};

// Stream operator
template <class trigger, class response>
std::ostream &operator<<(std::ostream &out, const match<trigger, response> &match) {
	return out;  //TODO: out << match.inbound << " | " << match.outbound;
}

} }

#endif
