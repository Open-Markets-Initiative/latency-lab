#ifndef OMI_ANALYSIS_PERCENTILE_HPP_
#define OMI_ANALYSIS_PERCENTILE_HPP_

#include <stdint.h>
#include <vector>
#include <algorithm>

namespace omi {
namespace analysis {
namespace percentile {

// Return index of nth number
static int index(size_t count, uint32_t percentile) {
    const auto offset = static_cast<int>(count * percentile / 100); // check this
    return offset > 0 ? offset - 1 : 0;
};

    // template version?

// Returns value at percentile
static double element(std::vector<double> &values, const uint32_t percentile) {
    if (values.begin() == values.end()) { return 0.; }

    auto index = percentile::index(values.size(), percentile);
    std::nth_element(values.begin(), values.begin() + index, values.end());

    return values[index];
}

    // template version?

// Return a vector of values as within percentile
static std::vector<double> range(const std::vector<double> &values, unsigned int lower, unsigned int upper) {
    // Throw exception on invalid args (check upper/lower)?
    if (values.begin() == values.end()) {
        return std::vector<double>{};
    }

    auto result = std::vector<double>(values);
    std::sort(result.begin(), result.end());

    auto low = percentile::index(result.size(), lower);
    auto high = percentile::index(result.size(), upper);

    // Todo:: return result
    return std::vector<double>(result.begin() + low, result.begin() + high);
}

} } }

#endif