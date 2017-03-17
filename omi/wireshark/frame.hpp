#ifndef OMI_WIRESHARK_FRAME_HPP_
#define OMI_WIRESHARK_FRAME_HPP_

#include <stdint.h>
#include <ostream>
#include <iomanip>
#include <iso646.h>

// Wireshark frame

namespace omi {
namespace wireshark {

struct frame {
    using number = uint32_t;
    using time = double;

  //// Member Variables ///////////

    number id;                     // Wireshark frame number
    time timestamp;                // Wireshark pcap timestamp

  //// Construction ///////////////

    // Default constructor
    frame()
      : id{ 0 }, timestamp{ 0. } {}

    // Standard constructor
    frame(number frame, time timestamp)
      : id{ frame }, timestamp{ timestamp } {}

  //// Implementation /////////////

    double microseconds() const {
        return timestamp * 1000000;
    }
};

// Stream operator
inline std::ostream &operator<<(std::ostream &out, const frame &frame) {
    return out << frame.id << "," << std::fixed << std::setprecision(9) << frame.timestamp;
}

} }

#endif
