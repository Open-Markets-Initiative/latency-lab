#ifndef OMI_HTML_ATTRIBUTES_HPP_
#define OMI_HTML_ATTRIBUTES_HPP_

#include <string>
#include <vector>

// Html attribute 

namespace omi {
namespace html {

struct attribute {
    std::string name;
    std::string value;

    explicit attribute(const std::string &name, const std::string &value)
      : name{ name }, value{ value } {}
};

// Stream operator
inline std::ostream &operator<<(std::ostream &out, const attribute &attribute) {
    return out << " " << attribute.name << "=\"" << attribute.value << "\"";
}

///////////////////////////////////

using attributes = std::vector<attribute>;

// Stream operator
inline std::ostream &operator<<(std::ostream &out, const attributes &attributes) {
    for (const auto &attribute : attributes) {
        out << attribute;
    }

    return out;
}

} } 

#endif
