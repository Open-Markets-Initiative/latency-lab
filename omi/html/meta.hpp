#ifndef OMI_HTML_META_TAG_HPP_
#define OMI_HTML_META_TAG_HPP_

#include <omi/html/elements.hpp>

#include <string>

// Html meta element 

namespace omi {
namespace html {

struct meta : html::tag {

    explicit meta(const std::string &name, const std::string &value, indent whitespace = indent::none)
     : tag{"meta", attribute{name, value}, whitespace} {}
};

// Stream operator (prints html meta tag)
inline std::ostream &operator<<(std::ostream &out, const meta &meta) {
    return out << static_cast<html::tag>(meta) << std::endl;
}

} }

#endif