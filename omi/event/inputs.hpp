#ifndef OMI_EVENT_INPUTS_HPP_
#define OMI_EVENT_INPUTS_HPP_

#include <string>

    // Matcher input files

namespace omi { 
namespace event {

struct inputs {
    std::string inbound;     // Inbound events file
    std::string outbound;    // Oubound events file
};

// Stream operator
inline std::ostream &operator<<(std::ostream &out, const inputs &file) {
    return out << "  Inbound: " << file.inbound << std::endl
               << "  Outbound: " << file.outbound << std::endl;
}

} }

#endif