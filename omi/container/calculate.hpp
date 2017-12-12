#ifndef OMI_CONTAINER_CALCULATE_HPP_
#define OMI_CONTAINER_CALCULATE_HPP_

#include <numeric>
#include <cmath>
#include <algorithm>

// Container calculation functions

namespace omi {
namespace calculate { // Is this the best namespace?

// Todo: full unit tests

// Calculate count
template <typename container>
static size_t count(container &values) {
    return values.size();
}

// Calculate minimum
template <typename container>
static typename container::value_type minimum(const container &values) {
    return values.size() == 0 ? typename container::value_type{} : *std::min_element(values.begin(), values.end());
}

// Calculate minimum
template <typename container>
static typename container::value_type maximum(const container &values) {
    return values.size() == 0 ? typename container::value_type{} : *std::max_element(values.begin(), values.end());
}

// Calculate sum
template <typename container>
static typename container::value_type sum(const container &values) {
    return std::accumulate(values.begin(), values.end(), typename container::value_type{});
}

// Calculate average
template <typename container>
static typename container::value_type average(const container &values) {
    // Verify that array has elements
    auto count = calculate::count(values);
    if (count == 0) { return typename container::value_type{}; }

    // Calculate average
    return calculate::sum(values) / count;
}

// Calculate standard deviation with pre calulated average
template <typename container>
static typename container::value_type deviation(container &values, typename container::value_type average) {
    // Todo: add static_asset that value type can be calculated
    // What about the 0?  Does that need to be checked also?

    // Verify that array has elements
    auto count = values.size();
    if (count == 0) { return static_cast<typename container::value_type>(0); }

    // Standard deviation
    typename std::remove_const<container>::type residuals(count);
    std::transform(values.begin(), values.end(), residuals.begin(), [&](auto && value) { return value - average; });
    auto squares = std::inner_product(residuals.begin(), residuals.end(), residuals.begin(), typename container::value_type{});

    return std::sqrt(squares / count);
}

// Calculate standard deviation
template <typename container>
static typename container::value_type deviation(const container &values) {
    return deviation(values, average(values));
}


} }

#endif