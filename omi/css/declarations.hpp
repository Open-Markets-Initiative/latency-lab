#ifndef OMI_CSS_DECLARATION_HPP_
#define OMI_CSS_DECLARATION_HPP_

#include <omi/source/whitespace.hpp>

#include <string>
#include <vector>

// Css declaration

namespace omi::css {

struct declaration {
    std::string property;
    std::string value;
    omi::whitespace whitespace;

    explicit declaration(const std::string &property, const std::string &value, const indent whitespace = indent::none)
      : property{ property }, value{ value }, whitespace{ whitespace } {}
};

inline std::ostream &operator<<(std::ostream &out, const declaration &rule) {
    return out << rule.whitespace << rule.property << ": " << rule.value << ";" << std::endl;
}

using declarations = std::vector<declaration>;

}

#endif