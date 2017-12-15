#ifndef OMI_COLLECTION_CALCULATE_HPP_
#define OMI_COLLECTION_CALCULATE_HPP_

#include <omi/collection/size.hpp>

#include <numeric>
#include <cmath>
#include <algorithm>

// Sequence calculation functions

namespace omi {
namespace collection {

// Todo: add static_asset that value type can be calculated
// Todo: full unit tests

// Calculate minimum
template <typename container>
static auto minimum(const container &collection) {
    return empty(collection) ? typename container::value_type{} : *std::min_element(std::begin(collection), std::end(collection));
}

// Calculate minimum
template <typename container>
static auto maximum(const container &collection) {
    return empty(collection) ? typename container::value_type{} : *std::max_element(std::begin(collection), std::end(collection));
}

///////////////////////

// Calculate sum
template <typename container>
static auto sum(const container &collection) {
    return std::accumulate(std::begin(collection), std::end(collection), typename container::value_type{});
}

// Calculate average
template <typename container>
static auto average(const container &elements) {
    auto count = collection::count(elements);
    return count > 0 ? collection::sum(elements) / count : typename container::value_type{};
}

// Calculate standard deviation with pre calulated average
template <typename container>
static auto deviation(container &values, typename container::value_type average) {
    // Verify that array has elements
    auto count = collection::count(values);
    if (count == 0) { return typename container::value_type{}; }

    // Standard deviation
    typename std::remove_const<container>::type residuals(count);
    std::transform(values.begin(), values.end(), residuals.begin(), [&](auto && value) { return value - average; });
    auto squares = std::inner_product(residuals.begin(), residuals.end(), residuals.begin(), typename container::value_type{});

    return std::sqrt(squares / count);
}

// Calculate standard deviation
template <typename container>
static auto deviation(const container &values) {
    return deviation(values, average(values));
}


} }

#endif