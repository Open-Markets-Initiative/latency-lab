#ifndef OMI_JAVASCRIPT_GOOGLE_CHART_HPP_
#define OMI_JAVASCRIPT_GOOGLE_CHART_HPP_

#include <omi/source/whitespace.hpp>

#include <iomanip>
#include <string>
#include <vector>

// Google chart javascript

namespace omi {
namespace javascript {
namespace google {

struct compchart {
    // script options
    omi::whitespace whitespace;
    std::string title;
    std::string element;
    std::map<std::string, std::vector<double>> values_map;

    // Constructor
    explicit compchart(std::map<std::string, std::vector<double>> values_map,
                       const std::string &element = "latency",
                       const std::string &title = "",
                       indent whitespace = indent::none)
            : whitespace{whitespace}, title{title}, element{element}, values_map{values_map} {}

};

// also note that this needs a min number of events

// Stream operator (prints javascript close tag)
inline std::ostream &operator<<(std::ostream &out, const compchart &chart) {

    for (std::map<std::string, std::vector<double>>::const_iterator it=chart.values_map.begin();
         it!=chart.values_map.end(); ++it) {
        out << html::script{"text/javascript"} << std::endl
            << chart.whitespace << "  google.charts.load('current', {'packages':['corechart', 'line']});" << std::endl
            << chart.whitespace << "  google.charts.setOnLoadCallback(drawChart_" + it->first + ");" << std::endl
            << std::endl
            << chart.whitespace << "  function drawChart_" + it->first + "() {" << std::endl
            << std::endl // TODO: Break this down into composable parts
            << chart.whitespace << "      var data = new google.visualization.DataTable();" << std::endl
            << chart.whitespace << "      data.addColumn('number', 'Event');" << std::endl
            << chart.whitespace << "      data.addColumn('number', 'Microseconds');" << std::endl
            << chart.whitespace << "      data.addRows([" << std::endl;

        std::vector<double> values = it->second;

        for (size_t i = 0, count = values.size(); i < count; ++i) {
            out << chart.whitespace << "        [" << i + 1 << ", " << std::fixed << std::setprecision(4) << values[i]
                << "]" << (i != count - 1 ? "," : "") << std::endl;
        }
        out << chart.whitespace << "      ]);" << std::endl
            << std::endl
            << chart.whitespace << "    var options = {" << std::endl;

        out << chart.whitespace << "      title: '" << it->first << "'," << std::endl;

        //if (not chart.title.empty()) {out << chart.whitespace << "      title: '" << chart.title <<"'," << std::endl;}

        out << chart.whitespace << "      legend: 'none'," << std::endl
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
            << chart.whitespace << "  var chart = new google.visualization.LineChart(document.getElementById('chart_"
            << it->first << "'));" << std::endl << std::endl
            << chart.whitespace << "  chart.draw(data, options);" << std::endl
            << chart.whitespace << "  }" << std::endl
            << html::close{"script"} << std::endl;
    }
            
    return out;
}}}}

#endif
