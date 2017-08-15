#ifndef OMI_MATCH_RESULTS_HPP_
#define OMI_MATCH_RESULTS_HPP_

#include <vector>
#include <omi/match/inputs.hpp>

// Matching results

namespace omi { 
namespace match {

struct results { // always pass this with auto to use templates?
    inputs path;                // Data Files
    std::vector<double> data;   // Matching Deltas
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