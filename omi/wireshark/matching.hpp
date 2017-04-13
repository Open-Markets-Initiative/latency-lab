#ifndef OMI_WIRESHARK_MATCHING_HPP_
#define OMI_WIRESHARK_MATCHING_HPP_

#include <omi/wireshark/matches.hpp>
#include <omi/analysis/deltas.hpp>

#include <vector>

// Matching wireshark events

namespace omi {
namespace wireshark {

struct matching {

  //// Member Variables ///////////

    wireshark::matches matches;
    std::vector<event> misses;

  //// Implementation /////////////

    // Match events and calculate deltas ...needs to go? add this to matches
    analysis::deltas deltas() const {
        // Loop through list events and create deltas
        analysis::deltas values;
        for (const auto &match : matches) {  // std::transform?       
            values.push_back({match.inbound.microseconds(), match.outbound.microseconds(), 9 }); // move to match
        }

        return values;
    }

};

// Stream operator
inline std::ostream &operator<<(std::ostream &out, const matching &events) {
    return out << "  Matched: " << events.matches.size() << std::endl
               << "  Unmatched: " << events.misses.size() << std::endl;
}

} }

#endif
