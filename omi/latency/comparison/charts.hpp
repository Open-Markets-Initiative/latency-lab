#ifndef OMI_LATENCY_COMPARISON_CHARTS_HPP_
#define OMI_LATENCY_COMPARISON_CHARTS_HPP_

#include <omi/match/runs.hpp>
#include <omi/javascript/google/chart.hpp>
#include <omi/html/declarations.hpp>

#include <iomanip>
#include <vector>

// Comparison charts

namespace omi {
namespace latency {
namespace comparison {

struct charts {
    // chart options
    omi::whitespace whitespace;
    match::runs runs;
    size_t precision{4};

    // Constructor
    explicit charts(const match::runs &runs, indent whitespace = indent::none)
      : whitespace{whitespace}, runs{runs} {}
};

// Stream operator
inline std::ostream &operator<<(std::ostream &out, const charts &chart) {
    out << html::src{ "https://www.gstatic.com/charts/loader.js" };
    for (auto&& run : chart.runs) {
        out << html::script{ "text/javascript" }
            << javascript::google::linechart{ run.data, text(run.period), chart.precision, run.name, "draw" + run.name, run.name + "chart"}
            << html::close{ "script" } << std::endl;
    }
            
    return out;
}

} } }

#endif