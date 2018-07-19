#ifndef OMI_FORMAT_NATURAL_HPP_
#define OMI_FORMAT_NATURAL_HPP_

#include <string>
#include <cctype> // use locale?
#include <sstream>

// Natural Text Methods

namespace omi::compare {

// Natural text comparison
inline bool natural(const std::string& a, const std::string& b) {
    // Check string empty
    if (a.empty()) { return true; }
    if (b.empty()) { return false; }

    // Check if character is same type
    if (std::isdigit(a[0]) && !std::isdigit(b.front())) { return true; }
    if (!std::isdigit(a[0]) && std::isdigit(b[0])) { return false; }

    // Check alpha values
    if (!std::isdigit(a[0]) && !std::isdigit(b[0])) {
        if (std::toupper(a[0]) == std::toupper(b[0])) {
            return natural(a.substr(1), b.substr(1));
        }

        return std::toupper(a[0]) < std::toupper(b[0]);
    }

    // Check digits
    std::istringstream issa(a);
    std::istringstream issb(b);
    int ia, ib;
    issa >> ia;
    issb >> ib;
    if (ia != ib) {
        return ia < ib;
    }

    auto anew(a);
    auto bnew(b);
    std::getline(issa, anew);
    std::getline(issb, bnew);

    return natural(anew, bnew);
}

}

#endif