#ifndef OMI_TYPES_SEQUENCE_NUMBER_HPP_
#define OMI_TYPES_SEQUENCE_NUMBER_HPP_

#include <cstdint>
#include <ostream>
#include <functional>
#include <iso646.h>

// Generic 8 byte sequence number

namespace omi {

struct seqnum {
    using type = uint64_t;

  ///// Construction //////////////

    // Default constructor
    seqnum() 
      : value{ 0 } {}

    // Standard constructor
    explicit seqnum(const type &number)
      : value{ number } {}

  ///// Methods ///////////////////

    // Return underlying value
    [[nodiscard]] type get() const {
        return value;
    }

  //// Properties /////////////////

  protected:
      type value;
};

///////////////////////////////////////////////

// Equals operator
inline bool operator==(const seqnum& lhs, const seqnum& rhs) {
    return lhs.get() == rhs.get();
}

// Not equals operator
inline bool operator!=(const seqnum& lhs, const seqnum& rhs) {
    return not operator==(lhs, rhs);
}

// Less than operator
inline bool operator<(const seqnum& lhs, const seqnum& rhs) {
    return lhs.get() < rhs.get();
}

// Greater than operator
inline bool operator>(const seqnum& lhs, const seqnum& rhs) {
    return operator<(rhs, lhs);
}

// Less than or equals operator
inline bool operator<=(const seqnum& lhs, const seqnum& rhs) {
    return not operator>(lhs, rhs);
}

// Greater than or equals operator
inline bool operator>=(const seqnum& lhs, const seqnum& rhs) {
    return not operator<(lhs, rhs);
}

// Stream operator
inline std::ostream &operator<<(std::ostream &out, const seqnum &number) {
    return out << number.get();
}

}

// Hash 
namespace std {
template<> struct hash<omi::seqnum> {
    size_t operator()(const omi::seqnum& number) const noexcept {
        return hash<omi::seqnum::type>()(number.get());
    }
};}

#endif