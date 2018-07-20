#ifndef OMI_MATCH_RESULT_HPP_
#define OMI_MATCH_RESULT_HPP_

#include <omi/match/inputs.hpp>
#include <omi/match/events.hpp>
#include <omi/match/run.hpp>

// Matching results

namespace omi::match {

template <typename inbound, typename outbound>
struct result {

  //// Member Variables ///////////

    std::string name;                  // Result Name
    inputs path;                       // Data Files
    events<inbound, outbound> data;    // Matched Events

  //// Methods ///////////

    // Return delta calculation by time period
    auto deltas(period period) const {
        return data.matched.deltas(period);
    }

    // Return run information
    auto run(const period period) const {
        return match::run{ name, path, period, deltas(period)};
    }

};

/*
// Stream operator
inline std::ostream &operator<<(std::ostream &out, const results &file) {
    return out << "  Inbound: " << file.inbound << std::endl
               << "  Outbound: " << file.outbound << std::endl;
}
*/

}

#endif