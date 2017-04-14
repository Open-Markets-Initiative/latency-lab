#ifndef OMI_WIRESHARK_MATCHING_HPP_
#define OMI_WIRESHARK_MATCHING_HPP_

#include <omi/wireshark/matches.hpp>
#include <omi/analysis/deltas.hpp>

#include <vector>

// Matching wireshark events

namespace omi {
namespace wireshark {

template <class inbound, class outbound>
struct matching {

  //// Member Variables ///////////


};

// Stream operator
template <class inbound, class outbound>
std::ostream &operator<<(std::ostream &out, const matching<inbound, outbound> &events) {
    return out << "  Matched: " << events.matches.size() << std::endl
               << "  Unmatched: " << events.misses.size() << std::endl;
}

} }

#endif
