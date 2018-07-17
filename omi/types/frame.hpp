#ifndef OMI_TYPES_FRAME_HPP_
#define OMI_TYPES_FRAME_HPP_

#include <stdint.h>
#include <ostream>
#include <iso646.h>

// Capture frame number

namespace omi {

struct frame {

  ///// Construction //////////////

    // Default constructor
    frame()
      : value{ 0 } {}

    // Standard constructor
    explicit frame(const uint64_t &number)
      : value{ number } {}

  ///// Methods ///////////////////

    // Cast operator
    explicit operator frame() const {
        return frame(value);
    }

    // Return underlying value
    uint64_t get() const {
        return value;
    }

  //// Properties /////////////////

  protected:

    uint64_t value;
};

///////////////////////////////////////////////

// Equals operator
inline bool operator==(const frame& lhs, const frame& rhs) {
    return lhs.get() == rhs.get();
}

// Not equals operator
inline bool operator!=(const frame& lhs, const frame& rhs) {
    return not operator==(lhs, rhs);
}

// Less than operator
inline bool operator<(const frame& lhs, const frame& rhs) {
    return lhs.get() < rhs.get();
}

// Greater than operator
inline bool operator>(const frame& lhs, const frame& rhs) {
    return operator<(rhs, lhs);
}

// Less than or equals operator
inline bool operator<=(const frame& lhs, const frame& rhs) {
    return not operator>(lhs, rhs);
}

// Greater than or equals operator
inline bool operator>=(const frame& lhs, const frame& rhs) {
    return not operator<(lhs, rhs);
}

// Stream operator
inline std::ostream &operator<<(std::ostream &out, const frame &number) {
    return out << number.get();
}

}

#endif