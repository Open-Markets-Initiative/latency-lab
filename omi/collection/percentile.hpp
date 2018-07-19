#ifndef OMI_COLLECTION_PERCENTILE_HPP_
#define OMI_COLLECTION_PERCENTILE_HPP_

#include <omi/collection/size.hpp>

#include <cstdint>
#include <algorithm>

namespace omi::collection {

// Return index of percentile
inline int index(const size_t count, const uint32_t percentile) {
    const auto offset = static_cast<int>(count * percentile / 100); // check this
    return offset > 0 ? offset - 1 : 0;
}

// Returns value at percentile (sorts array by nth_element)
template <typename container>
auto percentile(const uint32_t percentile, container &values) {
    if (empty(values)) {
        return typename container::value_type{};
    }

    auto index = collection::index(values.size(), percentile);
    std::nth_element(values.begin(), std::next(values.begin(), index), values.end());

    return values[index];
}

}

#endif