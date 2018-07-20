#ifndef OMI_STYLEHEET_OPTIONS_HPP_
#define OMI_STYLEHEET_OPTIONS_HPP_

#include <omi/source/whitespace.hpp>
#include <omi/html/declarations.hpp>
#include <omi/stylesheet/standard.hpp>

// Optional link to external style or inline default css declarations

namespace omi::stylesheet {

struct options {
    omi::whitespace whitespace;
    std::string import;

    explicit options(const std::string &file = "", indent whitespace = indent::none)
      : whitespace{ whitespace }, import{ file } {}
};

// Stream operator
inline std::ostream &operator<<(std::ostream &out, const options &options) {
    // Inlcude link to external file
    if (not options.import.empty()) { // TODO: check css extension?
        return out << html::link{ "stylesheet", "text/css", options.import };
    }

    // Include  standard directly
    return out << html::tag{ "style" }
               <<   stylesheet::standard{}
               << html::close{ "style" };
}

}

#endif