#ifndef OMI_TYPES_PERIOD_HPP_
#define OMI_TYPES_PERIOD_HPP_

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
    invalid,
    nanosecond,
    microsecond,
    millisecond,
    second,
    minute
};

// Format period as text 
inline period parse(const std::string& period) {
    // TODO: parse
    return period::microsecond;
}

// Format period as text 
inline const char * text(const period period) {
    switch(period) {
    case period::nanosecond:
        return "nanoseconds";
    case period::microsecond:
        return "microseconds";
    case period::millisecond:
        return "microseconds";
    case period::second:
        return "seconds";
    case period::minute:
        return "minutes";
    default:
        return "INVALID (PERIOD)";
    }
}

// Stream operator
inline std::ostream &operator<<(std::ostream &out, const period &period) {
    return out << text(period);
}

}

#endif