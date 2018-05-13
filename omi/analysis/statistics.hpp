#ifndef OMI_ANALYSIS_STATISTICS_HPP_
#define OMI_ANALYSIS_STATISTICS_HPP_

#include <vector>

#include <omi/collection/calculate.hpp>

// Calculate standard statistics

namespace omi {
namespace analysis {

template <typename container = std::vector<double>>
struct statistics {
    using value_type = typename container::value_type;

  //// Member Variables ///////////

    size_t count;
    value_type average;
    value_type deviation;

  //// Construction ///////////////

    // Default constructor
    statistics()
      : count{0} {}

    // Standard constructor
    explicit statistics(const container &values) {
        count = collection::count(values);
        average = collection::average(values);
        deviation = collection::deviation(values, average);
    }
};

// Stream operator
template <typename contanier>
std::ostream &operator<<(std::ostream &out, const statistics<contanier> &statistics) {
    return out << "  Average:   " << statistics.average << std::endl
               << "  Deviation: " << statistics.deviation << std::endl;
}

} }

#endif