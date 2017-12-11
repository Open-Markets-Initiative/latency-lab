#ifndef OMI_ANALYSIS_SUMMARY_HPP_
#define OMI_ANALYSIS_SUMMARY_HPP_

#include <omi/analysis/calculate.hpp>

#include <numeric>
#include <vector>

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

  //// Construction ///////////////

    // Default constructor
    summary() {}

    // Standard constructor
    explicit summary(const container &values) {
        count = values.size();
        average = calculate::average(values);
        deviation = calculate::deviation(values, average);
        minimum = calculate::minimum(values);
        maximum = calculate::maximum(values);
    }
};

// Stream operator
template <typename contanier>
std::ostream &operator<<(std::ostream &out, const summary<contanier> &summary) {
    return out << "  Average:   " << summary.average << std::endl
               << "  Deviation: " << summary.deviation << std::endl;
}

} }

#endif