#ifndef OMI_MATCH_RUN_HPP_
#define OMI_MATCH_RUN_HPP_

#include <vector>

#include <omi/types/period.hpp>
#include <omi/match/paths.hpp>

// Match run information

namespace omi::match {

struct run {

  //// Member Variables ///////////

    std::string name;                  // Result Name
    match::paths path;                 // Data Files
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

}

#endif