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

struct statistics {

  //// Member Variables ///////////

    size_t count { 0 };
    double average { 0. };
    double deviation { 0. };

    size_t precision { 4 };

  //// Construction ///////////////

    // Default constructor
    statistics() {}

    // Standard constructor
    explicit statistics(const std::vector<double> &values) {
        // Count
        count = values.size();
        if (count < 1) { return; }

        // Average
        auto sum = std::accumulate(values.begin(), values.end(), 0.0);
        average = sum / count;

        // Standard deviation
        std::vector<double> residuals(count);
        auto residual = [&](double value) { return value - average; };
        std::transform(values.begin(), values.end(), residuals.begin(), residual);
        auto squares = std::inner_product(residuals.begin(), residuals.end(), residuals.begin(), 0.0);
        deviation = std::sqrt(squares / count);
    }
};

// Stream operator
inline std::ostream &operator<<(std::ostream &out, const statistics &statistics) {
    return out << std::fixed << std::setprecision(statistics.precision)
               << "  Average:   " << statistics.average << std::endl
               << "  Deviation: " << statistics.deviation << std::endl;
}

} }

#endif