#ifndef OMI_MATCH_INPUTS_HPP_
#define OMI_MATCH_INPUTS_HPP_

#include <ostream>
#include <string>

// Match input files or directories

namespace omi::match {

struct inputs {
    std::string inbound;    // Inbound input
    std::string outbound;   // Outbound input
};

// Stream operator
inline std::ostream &operator<<(std::ostream &out, const inputs &input) {
    return out << "  Inbound: " << input.inbound << std::endl
               << "  Outbound: " << input.outbound << std::endl;
}

}

#endif