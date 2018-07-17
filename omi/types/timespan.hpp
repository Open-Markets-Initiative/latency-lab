#ifndef OMI_TYPES_TIMESPAN_HPP_
#define OMI_TYPES_TIMESPAN_HPP_

#include <omi/types/period.hpp>

#include <string>
#include <iso646.h>

// Simple 64bit portable inline timespan

namespace omi {

struct timespan {

  ///// Construction //////////////

    // Default constructor
    timespan()
      : value{ 0 } {}

    // Standard constructor
    explicit timespan(const int32_t &nanoseconds)
      : value{ static_cast<double>(nanoseconds) } {}

    // Standard constructor
    explicit timespan(const uint64_t &nanoseconds)
      : value{ static_cast<double>(nanoseconds) } {}

    explicit timespan(const double &nanoseconds)
      : value{ nanoseconds } {}

  /////////////////////////////////

    // Static constructor for nanoseconds
    static timespan nanoseconds(const double &time) {
        return timespan(time);
    }

    // Static constructor for nanoseconds
    static timespan nanoseconds(const uint64_t &start, const uint64_t &finish) {
        return timespan(finish - start);
    }

    // Static constructor for microseconds
    static timespan microseconds(const double &time) {
        return timespan(time * nanoseconds::per::microsecond);
    }

    // Static constructor for milliseconds
    static timespan milliseconds(const double &time) {
        return timespan(time * nanoseconds::per::millisecond);
    }

    // Static constructor for seconds
    static timespan seconds(const double &time) {
        return timespan(time * nanoseconds::per::second);
    }

  ///// Accessors /////////////////

    // Number of seconds
    double minutes() const {
        return value / nanoseconds::per::minute;
    }

    // Number of seconds
    double seconds() const {
        return value / nanoseconds::per::second;
    }

    // Number of microseconds
    double milliseconds() const {
        return value / nanoseconds::per::millisecond;
    }

    // Number of microseconds
    double microseconds() const {
        return value / nanoseconds::per::microsecond;
    }

    // Number of nanoseconds
    double nanoseconds() const {
        return value;
    }

  ///// Operators //////////////

    bool operator==(const uint64_t &time) const {
        return value == time;
    }

    timespan operator+(const timespan& other) const {
        return timespan(value + other.value);
    }

    timespan operator+=(const timespan& other) {
        value += other.value; return *this;
    }

    timespan operator-(const timespan& other) const {
        return timespan(value - other.value);
    }

    timespan operator-=(const timespan& other) {
        value -= other.value; return *this;
    }

  ///// Methods ///////////////////

    // Cast operator
    explicit operator timespan() const {
        return timespan(value);
    }

    // Return underlying value
    double get() const {
        return value;
    }

  //// Properties /////////////////

    std::string text() const {
        return std::string("todo");
    }

  protected:

    double value;
};

///////////////////////////////////

// Equals operator
inline bool operator==(const timespan& lhs, const timespan& rhs) {
    return lhs.get() == rhs.get();
}

// Not equals operator
inline bool operator!=(const timespan& lhs, const timespan& rhs) {
    return not operator==(lhs, rhs);
}

// Less than operator
inline bool operator<(const timespan& lhs, const timespan& rhs) {
    return lhs.get() < rhs.get();
}

// Greater than operator
inline bool operator>(const timespan& lhs, const timespan& rhs) {
    return operator<(rhs, lhs);
}

// Less than or equals operator
inline bool operator<=(const timespan& lhs, const timespan& rhs) {
    return not operator>(lhs, rhs);
}

// Greater than or equals operator
inline bool operator>=(const timespan& lhs, const timespan& rhs) {
    return not operator<(lhs, rhs);
}

// Stream operator
inline std::ostream & operator<<(std::ostream &out, const timespan& timestamp) {
  return out << timestamp.text();
}

}

#endif