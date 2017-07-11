#ifndef OMI_HTML_DOCTYPE_HPP_
#define OMI_HTML_DOCTYPE_HPP_

#include <string>
#include <omi/source/whitespace.hpp>

// Html doctype element 

namespace omi {
namespace html {

struct doctype {

    // Member variables
    std::string type;
    omi::whitespace whitespace;

    // Default constructor
    explicit doctype()
      : type{ "html" }, whitespace{ indent::none } {}

    explicit doctype(const std::string &type, indent whitespace = indent::none)
      : type{ type }, whitespace{ whitespace } {}
};

// Stream operator (prints doctype element)
inline std::ostream &operator<<(std::ostream &out, const doctype &doctype) {
    return out << "<!DOCTYPE " << doctype.type << ">" << std::endl;
}

} }

#endif