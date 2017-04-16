#ifndef OMI_ANALYSIS_PERCENTILES_HPP_
#define OMI_ANALYSIS_PERCENTILES_HPP_
 
#include <omi/analysis/percentile.hpp>

#include <iomanip>
#include <algorithm>
#include <vector>

    // Calculate percentiles of a vector of values

namespace omi {
namespace analysis {

struct percentiles {

  //// Member Variables ///////////

    size_t count { 0 };

    double p100 { 0.};
    double p99  { 0.};
    double p90  { 0.};
    double p75  { 0.};
    double p50  { 0.};
    double p25  { 0.};
    double p10  { 0.};
    double p01  { 0.};
    double p00  { 0.};

    size_t precision { 3 };

  //// Construction ///////////////

    // Default constructor
    percentiles() {}

    // Standard constructor (uses a copy - is this best?)
    explicit percentiles(std::vector<double> values) {
        if (values.empty()) { return; }

        // sort
        std::sort(values.begin(), values.end());

        // Get these before nth elment reorders the elements
        count = values.size();
        p00 = values.front();
        p100 = values.back();

        // What is the best order for these?
        p01 = percentile::element(values, 01);
        p10 = percentile::element(values, 10);
        p25 = percentile::element(values, 25);
        p50 = percentile::element(values, 50);
        p75 = percentile::element(values, 75);
        p90 = percentile::element(values, 90);
        p99 = percentile::element(values, 99);
    }
};


// Stream operator
inline std::ostream &operator<<(std::ostream &out, const percentiles &percentile) {
    return out << std::fixed << std::setprecision(percentile.precision)
               << "  Max: " << percentile.p100 << std::endl
               << "  99%: " << percentile.p99 << std::endl
               << "  90%: " << percentile.p90 << std::endl
               << "  75%: " << percentile.p75 << std::endl
               << "  50%: " << percentile.p50 << std::endl
               << "  25%: " << percentile.p25 << std::endl
               << "  10%: " << percentile.p10 << std::endl
               << "  01%: " << percentile.p01 << std::endl
               << "  Min: " << percentile.p00 << std::endl;
}

} }

#endif