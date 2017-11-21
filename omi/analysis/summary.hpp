#ifndef OMI_ANALYSIS_SUMMARY_HPP_
#define OMI_ANALYSIS_SUMMARY_HPP_

#include <numeric>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <cmath>

// Calculate standard summary statistics

namespace omi {
namespace analysis {

template <typename container = std::vector<double>>
struct summary {
    using value_type = typename container::value_type;

  //// Member Variables ///////////

    size_t count { 0 };
    value_type average { 0 };
    value_type deviation { 0 };
    value_type minimum{ 0 };
    value_type maximum{ 0 };

    // Display precision for decimal types
    size_t precision { 4 };

  //// Construction ///////////////

    // Default constructor
    summary() {}

    // Standard constructor
    explicit summary(const container &values, const size_t precision = 4) : precision{ precision } {
        // Count
        count = values.size();
        if (count < 1) { return; }

        // Minimum value
        minimum = *std::min_element(values.begin(), values.end());

        // Maximum value
        maximum = *std::max_element(values.begin(), values.end());

        // Average
        auto sum = std::accumulate(values.begin(), values.end(), static_cast<value_type>(0));
        average = sum / count;

        // Standard deviation
        container residuals(count);
        auto residual = [&](value_type value) { return value - average; };
        std::transform(values.begin(), values.end(), residuals.begin(), residual);
        auto squares = std::inner_product(residuals.begin(), residuals.end(), residuals.begin(), static_cast<value_type>(0));
        deviation = std::sqrt(squares / count);
    }
};

// Stream operator
template <typename contanier>
std::ostream &operator<<(std::ostream &out, const summary<contanier> &summary) {
    return out << std::fixed << std::setprecision(summary.precision)
               << "  Average:   " << summary.average << std::endl
               << "  Deviation: " << summary.deviation << std::endl;
}

} }

#endif