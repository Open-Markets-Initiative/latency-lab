#ifndef OMI_CSS_RULES_HPP_
#define OMI_CSS_RULES_HPP_

#include <omi/css/declarations.hpp>

#include <string>

// Css rule set

namespace omi::css {

struct rule {
    std::string selector;
    css::declarations declarations;
    omi::whitespace whitespace;

    explicit rule(const std::string &selector, const declaration &declaration, const indent whitespace = indent::none)
      : selector{ selector }, declarations{ declaration }, whitespace{ whitespace } {}

    explicit rule(const std::string &selector, const declaration &one, const declaration &two, const indent whitespace = indent::none)
      : selector{ selector }, declarations{ one, two }, whitespace{ whitespace } {}

    explicit rule(const std::string &selector, const declaration &one, const declaration &two, const declaration &three, indent whitespace = indent::none)
      : selector{ selector }, declarations{ one, two, three }, whitespace{ whitespace } {}

    explicit rule(const std::string &selector, const declaration &one, const declaration &two, const declaration &three, const declaration &four, indent whitespace = indent::none)
      : selector{ selector }, declarations{ one, two, three, four }, whitespace{ whitespace } {}

    explicit rule(const std::string &selector, const declaration &one, const declaration &two, const declaration &three, const declaration &four, const declaration &five, indent whitespace = indent::none)
      : selector{ selector }, declarations{ one, two, three, four, five }, whitespace{ whitespace } {}

    explicit rule(const std::string &selector, const declaration &one, const declaration &two, const declaration &three, const declaration &four, const declaration &five, const declaration &six, indent whitespace = indent::none)
      : selector{ selector }, declarations{ one, two, three, four, five, six }, whitespace{ whitespace } {}

};

inline std::ostream &operator<<(std::ostream &out, const rule &rule) {
    const auto whitespace = rule.whitespace;
    out << whitespace << rule.selector <<" {" << std::endl;

    for (const auto &declaration : rule.declarations) {
        out << whitespace << declaration;
    }

    return out << whitespace << "}" << std::endl;
}

}

#endif