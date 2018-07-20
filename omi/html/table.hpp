#ifndef OMI_HTML_TABLE_TAG_HPP_
#define OMI_HTML_TABLE_TAG_HPP_

#include <omi/html/tag.hpp>

// Html table element

namespace omi::html {

struct table : html::tag {

    explicit table(const std::string &Class, const indent whitespace = indent::none)
     : tag{"table", attribute{ "class", Class }, whitespace} {}
};

// Stream operator (prints table open tag)
inline std::ostream &operator<<(std::ostream &out, const table &table) {
    return out << static_cast<html::tag>(table);
}

}

#endif