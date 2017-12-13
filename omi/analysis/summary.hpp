#ifndef OMI_ANALYSIS_SUMMARY_HPP_
#define OMI_ANALYSIS_SUMMARY_HPP_

#include <omi/sequence/calculate.hpp>

#include <numeric>
#include <vector>

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
        count = sequence::count(values);
        average = sequence::average(values);
        deviation = sequence::deviation(values, average);
        minimum = sequence::minimum(values);
        maximum = sequence::maximum(values);
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