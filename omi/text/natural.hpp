#ifndef OMI_FORMAT_NATURAL_HPP_
#define OMI_FORMAT_NATURAL_HPP_

#include <string>
#include <cctype> // use locale?
#include <sstream>

// Natural Text Methods

namespace omi {
namespace format {

// Natural text comparison
inline bool natural(const std::string& a, const std::string& b) {
    // Standard checks
    if (a.empty()) { return true; }
    if (b.empty()) { return false; }

    // Check special characters
    if (std::isdigit(a[0]) && !std::isdigit(b[0])) {
        return true;}
    if (!std::isdigit(a[0]) && std::isdigit(b[0])) {
        return false;}
    if (!std::isdigit(a[0]) && !std::isdigit(b[0])) {
        if (std::toupper(a[0]) == std::toupper(b[0])) {
            return natural(a.substr(1), b.substr(1));
        }

        return std::toupper(a[0]) < std::toupper(b[0]);
    }

    // Both strings begin with digit, parse both as numbers
    std::istringstream issa(a);
    std::istringstream issb(b);
    int ia, ib;
    issa >> ia;
    issb >> ib;
    if (ia != ib) {
        return ia < ib;
    }

    // If digits are the same, remove numbers and recurse
    std::string anew, bnew;
    std::getline(issa, anew);
    std::getline(issb, bnew);

    return natural(anew, bnew);
}

} }

#endif