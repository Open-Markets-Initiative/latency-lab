#ifndef OMI_TYPES_PERIOD_HPP_
#define OMI_TYPES_PERIOD_HPP_

#include <algorithm>
#include <ostream>

// Time periods

namespace omi {

// Move to time definitions
namespace nanoseconds { namespace per { static constexpr uint64_t minute = 60000000000; } }
namespace nanoseconds { namespace per { static constexpr uint64_t second = 1000000000; } }
namespace nanoseconds { namespace per { static constexpr uint64_t microsecond = 1000; } }
namespace nanoseconds { namespace per { static constexpr uint64_t millisecond = 1000000; } }

// Time period enum
enum struct period {
    unknown,
    nanosecond,
    microsecond,
    millisecond,
    second,
    minute
};

// Format period as text 
inline const char * text(const period period) {
    switch(period) {
    case period::nanosecond:
        return "Nanoseconds";
    case period::microsecond:
        return "Microseconds";
    case period::millisecond:
        return "Microseconds";
    case period::second:
        return "Seconds";
    case period::minute:
        return "Minutes";
    default:
        return "INVALID (PERIOD)";
    }
}

// parse text as time period
namespace parse { inline auto period(const std::string& text) {
    // Convert text to lower
    auto value = text;
    std::transform(text.begin(), text.end(), value.begin(), ::tolower);

    // Dispatch to enum value
    if (value == "nanoseconds" ||
        value == "nanosecond" ||
        value == "nanos" ||
        value == "nano" ||
        value == "n") {
        return period::nanosecond;
    } if (value == "microseconds" ||
        value == "microsecond" ||
        value == "micros" ||
        value == "micro" ||
        value == "u") {
        return period::microsecond;
    } if (value == "milliseconds" ||
        value == "millsecond" ||
        value == "millis" ||
        value == "milli" ||
        value == "m") {
        return period::millisecond;
    } if (value == "seconds" ||
        value == "second" ||
        value == "s") {
        return period::second;
    } if (value == "minutes" ||
        value == "minute") {
        return period::minute;
    }

    return period::unknown;
}}

// Stream operator
inline std::ostream &operator<<(std::ostream &out, const period &period) {
    return out << text(period);
}

}

#endif