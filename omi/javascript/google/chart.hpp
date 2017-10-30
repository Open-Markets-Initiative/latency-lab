#ifndef OMI_JAVASCRIPT_GOOGLE_CHART_HPP_
#define OMI_JAVASCRIPT_GOOGLE_CHART_HPP_

#include <omi/source/whitespace.hpp>

#include <iomanip>
#include <string>
#include <vector>
#include <iso646.h>

// Google chart javascript

namespace omi {
namespace javascript {
namespace google {

struct linechart {
    // script options
    omi::whitespace whitespace;
    std::string title;
    std::string element;
    std::string unit;
    std::vector<double> values;
    size_t precision{ 4 };

    // Constructor
    explicit linechart(const std::vector<double> values, const std::string &unit, const size_t precision, const std::string &element = "latency", const std::string &title = "", const indent whitespace = indent::none)
      : whitespace{ whitespace }, title{ title }, element{ element }, unit{ unit }, values{ values }, precision{ precision } {}
};


// also note that this needs a min number of events

// Stream operator (prints javascript close tag)
inline std::ostream &operator<<(std::ostream &out, const linechart &chart) {
    out << chart.whitespace << "  google.charts.load('current', {'packages':['corechart', 'line']});" << std::endl
        << chart.whitespace << "  google.charts.setOnLoadCallback(linegraph);" << std::endl
        << std::endl
        << chart.whitespace << "  function linegraph() {" << std::endl << std::endl // TODO: Break this down into composable parts
        << chart.whitespace << "    var data = new google.visualization.DataTable();" << std::endl
        << chart.whitespace << "      data.addColumn('number', 'Event');" << std::endl
        << chart.whitespace << "      data.addColumn('number', '"<< chart.unit << "');" << std::endl
        << chart.whitespace << "      data.addRows([" << std::endl;
    for (size_t i = 0, count = chart.values.size(); i < count; ++i) {
        out << chart.whitespace << "        [" << i + 1 << ", " << std::fixed << std::setprecision(chart.precision) << chart.values[i] <<"]" << (i != count - 1 ? "," : "") << std::endl;
    }
    out << chart.whitespace << "      ]);" << std::endl
        << std::endl
        << chart.whitespace << "    var options = {" << std::endl;
    if (not chart.title.empty()) {out << chart.whitespace << "      title: '" << chart.title <<"'," << std::endl;}
    out << chart.whitespace << "      legend: 'none'," << std::endl
        << chart.whitespace << "      width: 1000," << std::endl // TODO: make these real options
        << chart.whitespace << "      height: 500," << std::endl
        << chart.whitespace << "      hAxis: {" << std::endl
        << chart.whitespace << "        title: 'Events'" << std::endl // TODO: calculate this kind of thing
        << chart.whitespace << "      }," << std::endl
        << chart.whitespace << "      vAxis: {" << std::endl
        << chart.whitespace << "        title: 'Latency (" << chart.unit << ")'," << std::endl
//        << chart.whitespace << "      ticks: [0, 500, 1000, 1500]" << std::endl need this
        << chart.whitespace << "      }" << std::endl
        << chart.whitespace << "  };" << std::endl
        << std::endl
        << chart.whitespace << "  var chart = new google.visualization.LineChart(document.getElementById('" << chart.element << "'));" << std::endl << std::endl
        << chart.whitespace << "  chart.draw(data, options);" << std::endl
        << chart.whitespace << "  }" << std::endl;

    return out;
}

} } }

#endif