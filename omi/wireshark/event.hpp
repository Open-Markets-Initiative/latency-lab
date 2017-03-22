#ifndef OMI_WIRESHARK_EVENT_HPP_
#define OMI_WIRESHARK_EVENT_HPP_

#include <omi/wireshark/frame.hpp>
#include <ostream>

// Wireshark event

namespace omi { 
namespace wireshark {

struct event {
    using id = std::string;

  //// Member Variables ///////////

    wireshark::frame frame;        // Wireshark Record info
    id identifier;                 // Event Identifier

  //// Construction ///////////////

    // Default constructor
    event() noexcept
      : frame{ 0, 0 }, identifier{ "" } {}

    // Standard constructor
    event(frame::number number, frame::time timestamp, id identifier) noexcept
      : frame{number, timestamp}, identifier{ identifier } {}
};


// Stream operator
inline std::ostream &operator<<(std::ostream &out, const event &event) {
    return out << event.frame << " [" << event.identifier.c_str() << "]";
}

} }

#endif
