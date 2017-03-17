#ifndef OMI_HTML_TAGS_HPP_
#define OMI_HTML_TAGS_HPP_

#include <omi/html/open.hpp>
#include <omi/source/whitespace.hpp>

// Html tags (open tag with crlf)

namespace omi {
namespace html {

struct tag : html::open {

    explicit tag() : open{} {}

    explicit tag(std::string name, indent whitespace = indent::none)
      : open{ name, whitespace }  {}

    explicit tag(std::string name, attribute attribute, indent whitespace = indent::none)
      : open{ name, attribute, whitespace } {}

    explicit tag(std::string name, attribute one, attribute two, indent whitespace = indent::none)
      : open{ name, one, two, whitespace } {}
};

// Stream operator (prints xml element open tag )
inline std::ostream &operator<<(std::ostream &out, const tag &tag) {
    return out << static_cast<html::open>(tag) << std::endl;
}

}  }

#endif
