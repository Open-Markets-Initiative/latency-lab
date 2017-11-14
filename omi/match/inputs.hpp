#ifndef OMI_MATCH_INPUTS_HPP_
#define OMI_MATCH_INPUTS_HPP_

#include <string>

// Matcher input files or directories

namespace omi { 
namespace match {

struct inputs {
    std::string inbound;    // Inbound events file
    std::string outbound;   // Outbound events file
};

// Stream operator
inline std::ostream &operator<<(std::ostream &out, const inputs &file) {
    return out << "  Inbound: " << file.inbound << std::endl
               << "  Outbound: " << file.outbound << std::endl;
}

} }

#endif