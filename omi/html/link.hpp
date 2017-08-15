#ifndef OMI_HTML_LINK_LEMENT_HPP_
#define OMI_HTML_LINK_LEMENT_HPP_

#include <omi/html/elements.hpp>
#include <omi/html/attributes.hpp>

#include <string>

// Html link element 

namespace omi {
namespace html {

struct link : html::element {

    explicit link(const std::string &rel, const std::string &type, const std::string &href, indent whitespace = indent::none)
     : element{"link", attribute{ "rel", rel }, attribute{ "type", type }, attribute{ "href", href }, whitespace} {}
};

// Stream operator
inline std::ostream &operator<<(std::ostream &out, const link &link) {
    return out << static_cast<html::element>(link);
}

} }

#endif