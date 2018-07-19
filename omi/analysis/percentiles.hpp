#ifndef OMI_ANALYSIS_PERCENTILES_HPP_
#define OMI_ANALYSIS_PERCENTILES_HPP_

#include <algorithm>
#include <vector> 

#include <omi/collection/percentile.hpp>

// Calculate percentiles of a container of values

namespace omi::analysis {

template <typename container = std::vector<double>>
struct percentiles {
    using value_type = typename container::value_type;

  //// Member Variables ///////////

    // Total number of values
    size_t count{ 0 };

    value_type p100{ 0 };
    value_type p99{ 0 };
    value_type p90{ 0 };
    value_type p75{ 0 };
    value_type p50{ 0 };
    value_type p25{ 0 };
    value_type p10{ 0 };
    value_type p01{ 0 };
    value_type p00{ 0 };

  //// Construction ///////////////

    // Default constructor
    percentiles() = default;

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
        p01 = collection::percentile(01, values);
        p10 = collection::percentile(10, values);
        p25 = collection::percentile(25, values);
        p50 = collection::percentile(50, values);
        p75 = collection::percentile(75, values);
        p90 = collection::percentile(90, values);
        p99 = collection::percentile(99, values);
    }
};


// Stream operator
template <typename contanier>
std::ostream &operator<<(std::ostream &out, const percentiles<contanier> &percentile) {
    return out << "  Max: " << percentile.p100 << std::endl
               << "  99%: " << percentile.p99 << std::endl
               << "  90%: " << percentile.p90 << std::endl
               << "  75%: " << percentile.p75 << std::endl
               << "  50%: " << percentile.p50 << std::endl
               << "  25%: " << percentile.p25 << std::endl
               << "  10%: " << percentile.p10 << std::endl
               << "  01%: " << percentile.p01 << std::endl
               << "  Min: " << percentile.p00 << std::endl;
}

}

#endif