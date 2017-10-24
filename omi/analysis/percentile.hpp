#ifndef OMI_ANALYSIS_PERCENTILE_HPP_
#define OMI_ANALYSIS_PERCENTILE_HPP_

#include <stdint.h>
#include <vector>
#include <algorithm>

namespace omi {
namespace analysis {
namespace percentile {

// Return index of percentile
static int index(const size_t count, const uint32_t percentile) {
    const auto offset = static_cast<int>(count * percentile / 100); // check this
    return offset > 0 ? offset - 1 : 0;
}

// Returns value at percentile (sorts array by nth_element)
template <typename container>
static typename container::value_type element(container &values, const uint32_t percentile) {
    // Default value is zero
    if (values.begin() == values.end()) {
        return static_cast<typename container::value_type>(0);
    }

    auto index = percentile::index(values.size(), percentile);
    std::nth_element(values.begin(), std::next(values.begin(), index), values.end());

    return values[index];
}

// Return a vector of values as within upper and lower percentile limits
template <typename container = std::vector<double>>
static container range(const container &values, const unsigned int lower, const unsigned int upper) {
    // Throw exception on invalid args (check upper/lower)?
    if (values.begin() == values.end()) {
        return container{};
    }

    // Copy and sort
    auto result = container(values);
    std::sort(result.begin(), result.end());

    // Locate range limits
    auto low = percentile::index(result.size(), lower);
    auto high = percentile::index(result.size(), upper);

    // TODO:: save a copy returning result?
    return container(std::next(result.begin(), low), std::next(result.begin(), high));
}

} } }

#endif