#ifndef OMI_COLLECTION_TRANSFORM_HPP_
#define OMI_COLLECTION_TRANSFORM_HPP_

#include <vector>
#include <algorithm>
#include <type_traits>

// Container transform

namespace omi::collection {

// Return value from function applied to container
template <typename container, typename function>
using made_from = decltype(std::declval<function>()(std::declval<typename container::value_type>()));

// Transform to vector according to operation
template <typename container, typename function>
auto transform(const container &collection, function && functor) {
    std::vector<made_from<container, function>> result;

    if constexpr (std::is_default_constructible_v<decltype(result)::value_type>) {
        result.resize(collection.size());
        std::transform(std::begin(collection), std::end(collection), std::begin(result), functor);
    } else {
        std::transform(std::begin(collection), std::end(collection), std::back_inserter(result), functor);
    }
    return result;
}

}

#endif