#ifndef OMI_ANALYSIS_RESULTS_HPP_
#define OMI_ANALYSIS_RESULTS_HPP_

#include <omi/analysis/percentiles.hpp>
#include <omi/analysis/statistics.hpp>

// Standard analysis results

namespace omi {
namespace analysis {

struct results {

  //// Member Variables ///////////

    percentiles percentiles;
    statistics standard;
    statistics steadystate;
    // add normalized (ie no outliers)
    // add outliers (check for repeating outlier pattern)

  //// Construction ///////////////

    // Standard constructor
    explicit results(const std::vector<double> &values) 
      : percentiles{ values },
        standard{ values, "Standard" },
        steadystate{ percentile::range(values, 0, 70), "Steady State" } {}
};

// Stream operator
inline std::ostream &operator<<(std::ostream &out, const results &results) {
    return out << results.percentiles << std::endl
               << results.standard << std::endl
               << results.steadystate << std::endl;
}

} }

#endif
