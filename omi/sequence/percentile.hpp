#ifndef OMI_SEQUENCE_PERCENTILE_HPP_
#define OMI_SEQUENCE_PERCENTILE_HPP_

#include <cstdint>
#include <algorithm>

namespace omi {
namespace sequence {

// Return index of percentile
static int index(const size_t count, const uint32_t percentile) {
    const auto offset = static_cast<int>(count * percentile / 100); // check this
    return offset > 0 ? offset - 1 : 0;
}

// Returns value at percentile (sorts array by nth_element)
template <typename container>
static auto percentile(container &values, const uint32_t percentile) {
    if (values.begin() == values.end()) {
        return typename container::value_type{};
    }

    auto index = sequence::index(values.size(), percentile);
    std::nth_element(values.begin(), std::next(values.begin(), index), values.end());

    return values[index];
}

} }

#endif