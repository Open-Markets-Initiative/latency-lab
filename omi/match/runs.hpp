#ifndef OMI_MATCH_RUNS_HPP_
#define OMI_MATCH_RUNS_HPP_

#include <omi/match/run.hpp>

// Matching results

namespace omi::match {

struct runs : std::vector<match::run> {};

/*
// Stream operator
inline std::ostream &operator<<(std::ostream &out, const results &file) {
    return out << "  Inbound: " << file.inbound << std::endl
               << "  Outbound: " << file.outbound << std::endl;
}
*/

}

#endif