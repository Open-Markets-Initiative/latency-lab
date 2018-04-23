#ifndef OMI_TYPES_RACE_HPP_
#define OMI_TYPES_RACE_HPP_

#include <algorithm>
#include <ostream>

// Race Sorting Types

namespace omi {

// Time period enum
enum struct race {
    unknown,
    factor,
    minimum,
    maximum,
    average,
    median
};

// Format race qualifier as text 
inline const char * text(const race race) {
    switch(race) {
    case race::factor:
        return "Factor";
    case race::minimum:
        return "Minimum";
    case race::maximum:
        return "Maximum";
    case race::average:
        return "Average";
    case race::median:
        return "Median";
    default:
        return "INVALID (RACE)";
    }
}

// parse text as race variable
namespace parse { inline auto race(const std::string& text) {
    // Convert text to lower
    auto value = text;
    std::transform(text.begin(), text.end(), value.begin(), ::tolower);

    // Dispatch to enum value
    if (value == "factor" ||
        value == "f") {
        return race::factor; }
    if (value == "minimum" ||
        value == "min" ||
        value == "n") {
        return race::minimum; }
    if (value == "maximum" ||
        value == "max" ||
        value == "x") {
        return race::maximum; }
    if (value == "median" ||
        value == "mid" ||
        value == "m") {
        return race::median; } 
    if (value == "average" ||
        value == "ave" ||
        value == "m") {
        return race::average; }

    return race::unknown;
}}

// Stream operator
inline std::ostream &operator<<(std::ostream &out, const race &race) {
    return out << text(race);
}

}

#endif