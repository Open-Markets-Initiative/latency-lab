#ifndef OMI_COLLECTION_TRANSFORM_HPP_
#define OMI_COLLECTION_TRANSFORM_HPP_

#include <vector>
#include <algorithm>
#include <type_traits>

// Container transform

namespace omi::collection {

// https://stackoverflow.com/questions/23871757/the-stdtransform-like-function-that-returns-transformed-container

// Transform vector according to operation
template <typename container, typename function, typename type = typename container::value_type>
auto transform(const container &collection, function && functor) {
    std::vector<decltype(std::declval<function>()(std::declval<type>()))> result;

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