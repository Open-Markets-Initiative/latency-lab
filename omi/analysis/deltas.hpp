#ifndef OMI_ANALYSIS_DELTAS_HPP_
#define OMI_ANALYSIS_DELTAS_HPP_

#include <omi/analysis/delta.hpp>

#include <algorithm>
#include <vector>

// Deltas

namespace omi {
namespace analysis {

struct deltas : std::vector<delta> {
    // Returns a vector of delta time values
    std::vector<double> values() const {
        std::vector<double> result(size());
        std::transform(begin(), end(), result.begin(), [](const delta &delta) { return delta.value; });
        return result;
    }
};

// Stream operator
inline std::ostream &operator<<(std::ostream &out, const deltas &values) {
    for (const auto &delta : values) {
        out << delta << std::endl;
    }

    return out;
}

} }

#endif