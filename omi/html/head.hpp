#ifndef OMI_HTML_HEAD_ELEMENT_HPP_
#define OMI_HTML_HEAD_ELEMENT_HPP_

#include <omi/html/tag.hpp>

#include <string>

// Html head element 

namespace omi {
namespace html {

struct head : html::tag {

    explicit head(indent whitespace = indent::none)
      : tag{"head", whitespace} {}
};

// Stream operator (prints html head open tag)
inline std::ostream &operator<<(std::ostream &out, const head &head) {
    return out << static_cast<html::tag>(head);
}

} } 

#endif
