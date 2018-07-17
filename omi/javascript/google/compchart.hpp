#ifndef OMI_JAVASCRIPT_GOOGLE_CHARTS_HPP_
#define OMI_JAVASCRIPT_GOOGLE_CHARTS_HPP_

#include <omi/source/whitespace.hpp>

#include <iomanip>
#include <string>
#include <vector>

// Google chart javascript

namespace omi {
namespace javascript {
namespace google {

struct charts {
    // script options
    omi::whitespace whitespace;
    std::string title;
    std::string element;
    match::runs runs;  // TODO: vector of double

    // Constructor
    explicit charts(const match::runs &runs,
                       const std::string &element = "latency",
                       const std::string &title = "",
                       indent whitespace = indent::none)
            : whitespace{whitespace}, title{title}, element{element}, runs{runs} {}

};

// also note that this needs a min number of events

// Stream operator (prints javascript close tag)
inline std::ostream &operator<<(std::ostream &out, const charts &chart) {

    for (auto&& run : chart.runs) {
        out << html::script{"text/javascript"} << std::endl
            << chart.whitespace << "  google.charts.load('current', {'packages':['corechart', 'line']});" << std::endl
            << chart.whitespace << "  google.charts.setOnLoadCallback(drawChart_" + run.name + ");" << std::endl //need a method to remove spaces
            << std::endl
            << chart.whitespace << "  function drawChart_" + run.name + "() {" << std::endl
            << std::endl // TODO: Break this down into composable parts
            << chart.whitespace << "      var data = new google.visualization.DataTable();" << std::endl
            << chart.whitespace << "      data.addColumn('number', 'Event');" << std::endl
            << chart.whitespace << "      data.addColumn('number', 'Microseconds');" << std::endl
            << chart.whitespace << "      data.addRows([" << std::endl;

        for (size_t i = 0, count = run.data.size(); i < count; ++i) {
            out << chart.whitespace << "        [" << i + 1 << ", " << std::fixed << std::setprecision(4) << run.data[i]
                << "]" << (i != count - 1 ? "," : "") << std::endl;
        }
        out << chart.whitespace << "      ]);" << std::endl
            << std::endl
            << chart.whitespace << "    var options = {" << std::endl;

        out << chart.whitespace << "      title: '" << run.name << "'," << std::endl
            << chart.whitespace << "      legend: 'none'," << std::endl
            << chart.whitespace << "      width: 1000," << std::endl // TODO: make these real options
            << chart.whitespace << "      height: 500," << std::endl
            << chart.whitespace << "      hAxis: {" << std::endl
            << chart.whitespace << "        title: 'Events'" << std::endl // TODO: calculate this kind of thing
            << chart.whitespace << "      }," << std::endl
            << chart.whitespace << "      vAxis: {" << std::endl
            << chart.whitespace << "        title: 'Latency (Microseconds)'," << std::endl
            << chart.whitespace << "      }" << std::endl
            << chart.whitespace << "  };" << std::endl
            << std::endl
            << chart.whitespace << "  var chart = new google.visualization.LineChart(document.getElementById('chart_" << run.name << "'));" << std::endl << std::endl
            << chart.whitespace << "  chart.draw(data, options);" << std::endl
            << chart.whitespace << "  }" << std::endl
            << html::close{"script"} << std::endl;
    }
            
    return out;
}

} } }

#endif