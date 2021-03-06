#ifndef OMI_ANALYSIS_RESULTS_HPP_
#define OMI_ANALYSIS_RESULTS_HPP_

#include <omi/analysis/percentiles.hpp>
#include <omi/analysis/statistics.hpp>
#include <omi/collection/range.hpp>

// Standard analysis results

namespace omi::analysis {

template <typename container = std::vector<double>> // Remove these defaults
struct results {

  //// Member Variables ///////////

    percentiles<container> percents;
    statistics<container> standard;
    statistics<container> steadystate;
    // add normalized (ie no outliers)
    // add outliers (check for repeating outlier pattern)

  //// Construction ///////////////

    // Standard constructor
    explicit results(const container &values) 
      : percents{ values },
        standard{ values },
        steadystate{ collection::range(values, 0, 70) } {}
};

// Static constructor
template <typename container>
auto of(const container &values) {
    return results<container>{ values };
}

// Stream operator
template <typename container = std::vector<double>>
std::ostream &operator<<(std::ostream &out, const results<container> &results) {
    return out << "Percentiles" << std::endl << results.percents
               << "Standard Statistics" << std::endl << results.standard
               << "Steady State Statistics" << std::endl << results.steadystate;
}

}

#endif