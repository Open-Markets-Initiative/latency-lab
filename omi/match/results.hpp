#ifndef OMI_MATCH_RESULTS_HPP_
#define OMI_MATCH_RESULTS_HPP_

#include <omi/match/inputs.hpp>
#include <omi/match/events.hpp>

// Matching results

namespace omi { 
namespace match {

template <typename inbound, typename outbound>
struct result {
    std::string name;                  // Result Name
    inputs path;                       // Data Files
    events<inbound, outbound> data;    // Matched Events
};

/*
// Stream operator
inline std::ostream &operator<<(std::ostream &out, const results &file) {
    return out << "  Inbound: " << file.inbound << std::endl
               << "  Outbound: " << file.outbound << std::endl;
}
*/

} }

#endif