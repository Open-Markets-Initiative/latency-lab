#ifndef OMI_HTML_CLOSE_HPP_
#define OMI_HTML_CLOSE_HPP_

#include <omi/source/whitespace.hpp>

// Html tags

namespace omi::html {

struct close {
    std::string name;
    omi::whitespace whitespace;

    explicit close(const std::string &name, const indent whitespace = indent::none)
      : name{ name }, whitespace{ whitespace } {}
};

// Stream operator (prints close element)
inline std::ostream &operator<<(std::ostream &out, const close &tag) {
    return out << tag.whitespace << "</" << tag.name + ">" << std::endl;
}

}

#endif