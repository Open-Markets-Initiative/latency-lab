#ifndef OMI_SEQUENCE_CALCULATE_HPP_
#define OMI_SEQUENCE_CALCULATE_HPP_

#include <numeric>
#include <cmath>
#include <algorithm>

// Sequence calculation functions

namespace omi {
namespace sequence {

// Todo: add static_asset that value type can be calculated
// Todo: full unit tests

// Is container empty?
template <typename container>
static bool empty(container &values) {
    return values.begin() == values.end();
}

// Calculate count
template <typename container>
static size_t count(container &values) {
    return values.size();
}

///////////////////////

// Calculate minimum
template <typename container>
static auto minimum(const container &values) {
    return empty(values) ? typename container::value_type{} : *std::min_element(values.begin(), values.end());
}

// Calculate minimum
template <typename container>
static auto maximum(const container &values) {
    return empty(values) ? typename container::value_type{} : *std::max_element(values.begin(), values.end());
}

///////////////////////

// Calculate sum
template <typename container>
static auto sum(const container &values) {
    return std::accumulate(values.begin(), values.end(), typename container::value_type{});
}

// Calculate average
template <typename container>
static auto average(const container &values) {
    auto count = sequence::count(values);
    return count > 0 ? sequence::sum(values) / count : typename container::value_type{};
}

// Calculate standard deviation with pre calulated average
template <typename container>
static auto deviation(container &values, typename container::value_type average) {
    // Verify that array has elements
    auto count = values.size();
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