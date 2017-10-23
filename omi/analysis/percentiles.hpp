#ifndef OMI_ANALYSIS_PERCENTILES_HPP_
#define OMI_ANALYSIS_PERCENTILES_HPP_
 
#include <omi/analysis/percentile.hpp>

#include <iomanip>
#include <algorithm>
#include <vector>

    // Calculate percentiles of a container of values

namespace omi {
namespace analysis {

template <typename container = std::vector<double>>
struct percentiles {
    using value_type = typename container::value_type;

  //// Member Variables ///////////

    size_t count { 0 };

    value_type p100 { 0 };
    value_type p99  { 0 };
    value_type p90  { 0 };
    value_type p75  { 0 };
    value_type p50  { 0 };
    value_type p25  { 0 };
    value_type p10  { 0 };
    value_type p01  { 0 };
    value_type p00  { 0 };

    size_t precision { 3 }; // Set this globally?

  //// Construction ///////////////

    // Default constructor
    percentiles() {}

    // Standard constructor
    explicit percentiles(const container &original) {
        if (original.empty()) { return; }

        // Copy and sort
        auto values = original;
        std::sort(values.begin(), values.end());

        // Get these before percentiles reorders the elements
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
template <typename contanier>
std::ostream &operator<<(std::ostream &out, const percentiles<contanier> &percentile) {
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