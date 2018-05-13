#ifndef OMI_ANALYSIS_SUMMARY_HPP_
#define OMI_ANALYSIS_SUMMARY_HPP_

#include <numeric>
#include <vector>

#include <omi/collection/calculate.hpp>

// Calculate standard summary statistics

namespace omi {
namespace analysis {

template <typename container = std::vector<double>>
struct summary {
    using value_type = typename container::value_type;

  //// Member Variables ///////////

    size_t count;
    value_type average;
    value_type deviation;
    value_type minimum;
    value_type maximum;

  //// Construction ///////////////

    // Default constructor
    summary() noexcept
      : count{ 0 } {}

    // Standard constructor
    explicit summary(const container &values) {
        count = collection::count(values);
        average = collection::average(values);
        deviation = collection::deviation(values, average);
        minimum = collection::minimum(values);
        maximum = collection::maximum(values);
    }
};

// Stream operator
template <typename container>
std::ostream &operator<<(std::ostream &out, const summary<container> &summary) {
    return out << "  Average:   " << summary.average << std::endl
               << "  Deviation: " << summary.deviation << std::endl
               << "  Minimum:   " << summary.minimum << std::endl
               << "  Maximum: " << summary.maximum << std::endl;
}

} }

#endif