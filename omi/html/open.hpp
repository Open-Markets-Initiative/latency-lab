#ifndef OMI_HTML_OPEN_HPP_
#define OMI_HTML_OPEN_HPP_

#include <omi/html/attributes.hpp>
#include <omi/source/whitespace.hpp>

// Html open tag (no crlf)

namespace omi {
namespace html {

struct open {
    std::string name;
    html::attributes attributes;
    omi::whitespace whitespace;

    // Constructors
    explicit open() {}

    explicit open(std::string name, indent whitespace = indent::none)
      : name{ name }, whitespace{ whitespace }  {}

    explicit open(std::string name, attribute attribute, indent whitespace = indent::none)
      : name{ name }, attributes{ attribute }, whitespace{ whitespace } {}

    explicit open(std::string name, attribute one, attribute two, indent whitespace = indent::none)
      : name{ name }, attributes{ one, two }, whitespace{ whitespace } {}
};

// Stream operator (prints xml element open tag )
inline std::ostream &operator<<(std::ostream &out, const open &tag) {
    return out << tag.whitespace << "<" << tag.name << tag.attributes << ">";
}

} }

#endif