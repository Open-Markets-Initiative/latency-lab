#ifndef OMI_HTML_JAVASCRIPT_SRC_ELEMENT_HPP_
#define OMI_HTML_JAVASCRIPT_SRC_ELEMENT_HPP_

#include <omi/html/elements.hpp>

// Html javascript src element

namespace omi::html {

struct src : html::element {

    explicit src(const std::string &src, const indent whitespace = indent::none)
      : element{ "script", attribute{ "type", "text/javascript" }, attribute{ "src", src }, whitespace } {}
};

// Stream operator (prints html script element with src for javascript)
inline std::ostream &operator<<(std::ostream &out, const src &src) {
    return out << static_cast<html::element>(src);
}

}

#endif