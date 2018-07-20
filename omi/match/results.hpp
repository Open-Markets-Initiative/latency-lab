#ifndef OMI_MATCH_RESULTS_HPP_
#define OMI_MATCH_RESULTS_HPP_

#include <omi/match/result.hpp>
#include <omi/match/runs.hpp>

// Matching runs

namespace omi::match {

template <typename inbound, typename outbound>
struct results : std::vector<match::result<inbound, outbound>> {

  //// Methods ///////////

    // Return deltas by period
    auto runs(const period period) const {
        match::runs runs;
        for (const auto &result : *this) {
            runs.push_back(result.run(period));
        }
        return runs;
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