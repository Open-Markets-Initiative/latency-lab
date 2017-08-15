#ifndef OMI_SOURCE_WHITESPACE_HPP_
#define OMI_SOURCE_WHITESPACE_HPP_

#include <string>

// Xml whitespace

namespace omi {

enum class indent {
    none,
    two,
    four,
    tab
};

struct whitespace {
    indent type;

    explicit whitespace(indent type = indent::none)
      : type{ type } {}
};

inline std::ostream &operator<<(std::ostream &out, const whitespace &whitespace) {
    switch (whitespace.type) {
        case indent::two:
            return out << "  ";
        case indent::four:
            return out << "    ";
        case indent::tab:
            return out << '\t';
        case indent::none:
        default:
            return out;
    }
}

}

#endif