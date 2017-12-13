#ifndef OMI_SEQUENCE_RANGE_HPP_
#define OMI_SEQUENCE_RANGE_HPP_

#include <omi/sequence/percentile.hpp>

#include <vector>
#include <algorithm>

namespace omi {
namespace sequence {

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
    auto low = index(result.size(), lower);
    auto high = index(result.size(), upper);

    // TODO:: save a copy returning result?
    return container(std::next(result.begin(), low), std::next(result.begin(), high));
}

} }

#endif