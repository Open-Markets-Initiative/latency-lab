#ifndef OMI_TYPES_TIMESTAMP_HPP_
#define OMI_TYPES_TIMESTAMP_HPP_

#include <iostream>
#include <string>
#include <chrono>
#include <iso646.h>

// Simple 64bit portable inline timestamp

namespace omi {

// Better way to do this?
namespace nanoseconds { namespace per { static constexpr uint64_t second = 1000000000; }}
namespace nanoseconds { namespace per { static constexpr uint64_t microsecond = 1000; }}
namespace nanoseconds { namespace per { static constexpr uint64_t millisecond = 1000000; }}

struct timestamp {

  ///// Construction //////////////

    // Default constructor
    timestamp() 
      : value{ 0 } {}

    // Standard constructor
    explicit timestamp(const uint64_t &nanoseconds) 
      : value{ nanoseconds } {}

    // Construct from seconds and nanoseconds
    explicit timestamp(const uint64_t &seconds, const uint64_t &nanoseconds) 
      : value{ seconds + nanoseconds::per::second + nanoseconds } {}

  /////////////////////////////////

    // Get current time from system clock
    static timestamp now() {
        auto duration = std::chrono::system_clock::now().time_since_epoch();
        return nanoseconds(std::chrono::duration_cast<std::chrono::nanoseconds>(duration).count());
    }

  /////////////////////////////////

    // Static constructor for nanoseconds
    static timestamp nanoseconds(const uint64_t &time) {
        return timestamp(time);
    }

    static timestamp microseconds(const uint64_t &time) {
        return timestamp(time * nanoseconds::per::microsecond);
    }

    static timestamp milliseconds(const uint64_t &time) {
        return timestamp(time * nanoseconds::per::millisecond);
    }

    static timestamp seconds(const uint64_t &time) {
        return timestamp(time * nanoseconds::per::second);
    }

    /* // need one for time_t etc
    explicit timestamp(const struct timeval &time)
    : fundamental<timestamp, uint64_t>((time.tv_sec * nanos) + (time.tv_usec * nanos)) {}

    */

  ///// Accessors /////////////////

    // Number of seconds since epoch
    uint64_t seconds() const {
        return value / nanoseconds::per::second;
    }

    // Number of microseconds since epoch
    uint64_t microseconds() const {
        return value / nanoseconds::per::microsecond;
    }

    // Number of nanoseconds since epoch
    uint64_t nanoseconds() const {
        return value;
    }

  ///// Operators //////////////

    bool operator==(const uint64_t &time) const {
        return value == time;
    }

    timestamp operator+(const timestamp& other) const {
        return timestamp(value + other.value);
    }

    timestamp operator+=(const timestamp& other) {
        value += other.value; return *this;
    }

    timestamp operator-(const timestamp& other) const {
        return timestamp(value - other.value);
    }

    timestamp operator-=(const timestamp& other) {
        value -= other.value; return *this;
    }

  ///// Methods ///////////////////

    // Cast operator
    explicit operator timestamp() const {
        return timestamp(value);
    }

    // Return underlying value
    uint64_t get() const {
        return value;
    }

  //// Properties /////////////////

    std::string text() const {
        return std::string("todo");
    }

  protected:

    uint64_t value;
};


///////////////////////////////////////////////

// Equals operator
inline bool operator==(const timestamp& lhs, const timestamp& rhs) {
    return lhs.get() == rhs.get();
}

// Not equals operator
inline bool operator!=(const timestamp& lhs, const timestamp& rhs) {
    return not operator==(lhs, rhs);
}

// Less than operator
inline bool operator<(const timestamp& lhs, const timestamp& rhs) {
    return lhs.get() < rhs.get();
}

// Greater than operator
inline bool operator>(const timestamp& lhs, const timestamp& rhs) {
    return operator<(rhs, lhs);
}

// Less than or equals operator
inline bool operator<=(const timestamp& lhs, const timestamp& rhs) {
    return not operator>(lhs, rhs);
}

// Greater than or equals operator
inline bool operator>=(const timestamp& lhs, const timestamp& rhs) {
    return not operator<(lhs, rhs);
}

// Stream operator
inline std::ostream & operator<<(std::ostream &out, const timestamp &timestamp) {
  return out << timestamp.text();
}

}

#endif