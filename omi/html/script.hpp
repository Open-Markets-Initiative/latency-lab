#ifndef OMI_HTML_SCRIPT_ELEMENTS_HPP_
#define OMI_HTML_SCRIPT_ELEMENTS_HPP_

#include <omi/html/tag.hpp>

#include <string>

// Html script tag

namespace omi::html {

struct script : html::tag {

    explicit script(const std::string &type, indent whitespace = indent::none)
      : tag{ "script", html::attribute{ "type", type }, whitespace } {}
};

// Stream operator (prints html script open tag)
inline std::ostream &operator<<(std::ostream &out, const script &script) {
    return out << static_cast<html::tag>(script);
}

}

#endif