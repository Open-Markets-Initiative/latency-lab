#ifndef OMI_MATCH_RUN_HPP_
#define OMI_MATCH_RUN_HPP_

#include <omi/types/period.hpp>
#include <omi/match/inputs.hpp>

#include <vector>

// Match run information

namespace omi { 
namespace match {

struct run {

  //// Member Variables ///////////

    std::string name;                  // Result Name
    inputs path;                       // Data Files
    omi::period period;                // Delta interval
    std::vector<double> data;          // Matched deltas
};

/*
// Stream operator
inline std::ostream &operator<<(std::ostream &out, const run &file) {
    return out << "  Inbound: " << file.inbound << std::endl
               << "  Outbound: " << file.outbound << std::endl;
}
*/

} }

#endif