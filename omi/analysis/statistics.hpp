#ifndef OMI_ANALYSIS_STATISTICS_HPP_
#define OMI_ANALYSIS_STATISTICS_HPP_

#include <numeric>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <cmath>

// Calculate standard statistics

namespace omi {
namespace analysis {

template <typename container = std::vector<double>>
struct statistics {
    using value_type = typename container::value_type;

  //// Member Variables ///////////

    size_t count { 0 };
    value_type average { 0 };
    value_type deviation { 0 };

    // Display precision for decimal types
    size_t precision { 4 };

  //// Construction ///////////////

    // Default constructor
    statistics() {}

    // Standard constructor
    explicit statistics(const container &values) {
        // Count
        count = values.size();
        if (count < 1) { return; }

        // Average
        auto sum = std::accumulate(values.begin(), values.end(), static_cast<value_type>(0));
        average = sum / count;

        // Standard deviation
        container residuals(count);
        auto residual = [&](double value) { return value - average; };
        std::transform(values.begin(), values.end(), residuals.begin(), residual);
        auto squares = std::inner_product(residuals.begin(), residuals.end(), residuals.begin(), static_cast<value_type>(0));
        deviation = std::sqrt(squares / count);
    }
};

// Stream operator
template <typename contanier>
std::ostream &operator<<(std::ostream &out, const statistics<contanier> &statistics) {
    return out << std::fixed << std::setprecision(statistics.precision)
               << "  Average:   " << statistics.average << std::endl
               << "  Deviation: " << statistics.deviation << std::endl;
}

} }

#endif