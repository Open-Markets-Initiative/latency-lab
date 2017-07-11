#ifndef OMI_HTML_HEADING_ELEMENTS_HPP_
#define OMI_HTML_HEADING_ELEMENTS_HPP_

#include <omi/html/elements.hpp>

#include <string>

// Html heading elements 

namespace omi {
namespace html {

struct h1 : html::element {

    explicit h1(const std::string &value, indent whitespace = indent::none)
     : element{"h1", value, whitespace} {}
};

inline std::ostream &operator<<(std::ostream &out, const h1 &h1) {
    return out << static_cast<html::element>(h1);
}

///////////////////////////////////

struct h2 : html::element {

    explicit h2(const std::string &value, indent whitespace = indent::none)
      : element{ "h2", value, whitespace } {}
};

inline std::ostream &operator<<(std::ostream &out, const h2 &h2) {
    return out << static_cast<html::element>(h2);
}

///////////////////////////////////

struct h3 : html::element {

    explicit h3(const std::string &value, indent whitespace = indent::none)
     : element{"h3", value, whitespace} {}
};

inline std::ostream &operator<<(std::ostream &out, const h3 &h3) {
    return out << static_cast<html::element>(h3);
}

///////////////////////////////////

struct h4 : html::element {

    explicit h4(const std::string &value, indent whitespace = indent::none)
      : element{ "h4", value, whitespace } {}
};

inline std::ostream &operator<<(std::ostream &out, const h4 &h4) {
    return out << static_cast<html::element>(h4);
}

///////////////////////////////////

struct h5 : html::element {

    explicit h5(const std::string &value, indent whitespace = indent::none)
      : element{ "h5", value, whitespace } {}
};

inline std::ostream &operator<<(std::ostream &out, const h5 &h5) {
    return out << static_cast<html::element>(h5);
}

///////////////////////////////////

struct h6 : html::element {

    explicit h6(const std::string &value, indent whitespace = indent::none)
        : element{ "h6", value, whitespace } {}
};

inline std::ostream &operator<<(std::ostream &out, const h6 &h6) {
    return out << static_cast<html::element>(h6);
}

} }

#endif