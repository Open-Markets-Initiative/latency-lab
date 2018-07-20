#ifndef OMI_HTML_PARAGRAPH_ELEMENT_HPP_
#define OMI_HTML_PARAGRAPH_ELEMENT_HPP_

#include <omi/html/elements.hpp>

#include <string>

// Html paragraph element

namespace omi::html {

struct p : html::element {

    explicit p(const std::string &value, indent whitespace = indent::none)
     : element{"p", value, whitespace} {}
};

inline std::ostream &operator<<(std::ostream &out, const p &p) {
    return out << static_cast<html::element>(p);
}

}

#endif