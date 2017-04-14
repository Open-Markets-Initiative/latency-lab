#ifndef OMI_EVENT_INFO_HPP_
#define OMI_EVENT_INFO_HPP_

#include <ostream>

// Matched event info

namespace omi {
namespace event {

template <class inbound, class outbound>
struct info {
  // TODO: Make this use types from match...get from records using static assert

  //// Member Variables ///////////

   // double initial;                  // Inbound trigger event

  //// Construction ///////////////

    // Standard constructor
    info(const inbound &trigger, const outbound &response) {}

};

// Stream operator
template <class inbound, class outbound>
std::ostream &operator<<(std::ostream &out, const info<inbound, outbound> &info) {
    return out;  // TODO
}

} }

#endif
