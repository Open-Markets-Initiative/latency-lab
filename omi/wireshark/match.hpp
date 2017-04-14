#ifndef OMI_WIRESHARK_MATCH_HPP_
#define OMI_WIRESHARK_MATCH_HPP_

#include <iostream>

// Matched events 

namespace omi { 
namespace wireshark {

template <class trigger, class response>
struct match {

  //// Member Variables ///////////

	trigger inbound;                  // Inbound trigger event wireshark frame
	response outbound;                // Triggered outbound 

  //// Construction ///////////////

    // Standard constructor
    match(const trigger &inbound, const response &outbound)
      : inbound{ inbound }, outbound{ outbound }{}
};

// Stream operator
template <class trigger, class response>
std::ostream &operator<<(std::ostream &out, const match<trigger, response> &match) {
	return out;  //out << match.inbound << " | " << match.outbound;
}

} }

#endif
