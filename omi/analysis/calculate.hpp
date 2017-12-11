#ifndef OMI_ANALYSIS_CALCULATE_HPP_
#define OMI_ANALYSIS_CALCULATE_HPP_

#include <numeric>
#include <cmath>

// Calculation functions

namespace omi {
namespace analysis {
namespace calculate { // move these to container?

// todo refactor
// full unit tests


// Calculate minimum
template <typename container>
static typename container::value_type minimum(container &values) {
    return values.size() == 0 ? static_cast<typename container::value_type>(0) : *std::min_element(values.begin(), values.end());
}

// Calculate minimum
template <typename container>
static typename container::value_type maximum(container &values) {
    return values.size() == 0 ? static_cast<typename container::value_type>(0) : *std::max_element(values.begin(), values.end());
}

// Calculate average
template <typename container>
static typename container::value_type average(container &values) {
    // Verify that array has elements
    auto count = values.size();
    if (count == 0) { return static_cast<typename container::value_type>(0); }

    // Calculate average
    auto sum = std::accumulate(values.begin(), values.end(), static_cast<typename container::value_type>(0));
    return sum / count;;
}

// Returns deviation
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
    auto squares = std::inner_product(residuals.begin(), residuals.end(), residuals.begin(), static_cast<typename container::value_type>(0));

    return std::sqrt(squares / count);
}

// Caluculation standard deviation
template <typename container>
static typename container::value_type deviation(container &values) {
    return deviation(values, average(values));
}


} } }

#endif