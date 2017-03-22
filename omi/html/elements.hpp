#ifndef OMI_HTML_ELEMENTS_HPP_
#define OMI_HTML_ELEMENTS_HPP_

#include <omi/html/tag.hpp>
#include <omi/html/close.hpp>

// Html element

namespace omi {
namespace html {

struct element {
    std::string name;
    html::attributes attributes;
    std::string value;
    omi::whitespace whitespace;
    
    // Constructors
    explicit element() {}

    explicit element(const std::string &name, indent whitespace = indent::none)
      : name{ name }, whitespace{ whitespace } {}

    explicit element(const std::string &name, const std::string &value, indent whitespace = indent::none)
      : name{ name }, value{ value }, whitespace{ whitespace } {}

    explicit element(const std::string &name, attribute attribute, indent whitespace = indent::none)
      : name{ name }, attributes{ attribute }, whitespace{ whitespace } {}

    explicit element(const std::string &name, attribute one, attribute two, indent whitespace = indent::none)
      : name{ name }, attributes{ one, two }, whitespace{ whitespace } {}

    explicit element(const std::string &name, html::attributes attributes, indent whitespace = indent::none)
      : name{ name }, attributes{ attributes }, whitespace{ whitespace } {}
};

// Stream operator (prints html element on single line)
inline std::ostream &operator<<(std::ostream &out, const element &element) {
    return out << element.whitespace << "<" << element.name << element.attributes << ">" << element.value << close{ element.name };
}

}  }

#endif
