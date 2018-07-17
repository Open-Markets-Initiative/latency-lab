#ifndef OMI_HTML_TITLE_ELEMENT_HPP_
#define OMI_HTML_TITLE_ELEMENT_HPP_

#include <omi/html/elements.hpp>

// Html title element

namespace omi {
namespace html {

struct title : html::element {

    explicit title(const std::string &value, const indent whitespace = indent::none)
      : html::element{ "title", value, whitespace } {}
};

// Stream operator (print html title element)
inline std::ostream &operator<<(std::ostream &out, const title &title) {
    return out << static_cast<html::element>(title) << std::endl;
}

} }

#endif