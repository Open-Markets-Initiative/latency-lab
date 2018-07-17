#ifndef OMI_LATENCY_PAGE_CHARTS_HPP_
#define OMI_LATENCY_PAGE_CHARTS_HPP_

#include <omi/match/runs.hpp>
#include <omi/html/declarations.hpp>
#include <omi/javascript/google/chart.hpp>

// Page charts

namespace omi {
namespace latency {
namespace page {

struct charts {
    // chart options
    omi::whitespace whitespace;
    match::runs runs;
    size_t precision{4};

    // make using google optional

    // Constructor
    explicit charts(const match::runs &runs, indent whitespace = indent::none)
      : whitespace{whitespace}, runs{runs} {}
};

// Stream operator
inline std::ostream &operator<<(std::ostream &out, const charts &chart) {
    out << "  google.charts.load('current', {'packages':['corechart', 'line']});" << std::endl << std::endl; // make method for this
    for (auto && run : chart.runs) {
        out << javascript::google::linechart{ run.data, text(run.period), chart.precision, run.name, "draw" + run.name, run.name + "chart"}
            << std::endl;
    }

    return out;
}

} } }

#endif