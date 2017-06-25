#ifndef OMI_LATENCY_COMPARISON_COMPONENTS_HPP_
#define OMI_LATENCY_COMPARISON_COMPONENTS_HPP_

#include <omi/table/statistics.hpp>
#include <omi/table/percentiles.hpp>
#include <omi/javascript/google/compchart.hpp>
#include <omi/styles/one.hpp>
#include <omi/source/write.hpp>
#include <omi/latency/comparison/configuration.hpp>
#include <omi/event/inputs.hpp>
#include <omi/html/sections.hpp>
#include <map>

// Generate multi-run latency comparison html report

namespace omi { 
namespace latency {
namespace comparison {

struct components {

  //// Member Variables ///////////

    comparison::configuration layout;       // Common layout options
    event::inputs files;                    // Input files
    std::map<std::string, std::vector<double>> delta_map; // Ordered event times for each run

  //// Methods ////////////////////

    // Write html report to path
    void write(const std::string &path) const {
        source::write(*this, path);
    }
};


// Stream operator (composes html report from layout and data) 
inline std::ostream &operator<<(std::ostream &out, const components &report) {
    return out << html::doctype{"html"}
               << html::tag{"html"}
               << std::endl
               << html::tag{"head"}
               <<   "<LINK REL=StyleSheet HREF=\"omi.css\" TITLE=\"Default\"/>" << std::endl
               <<   "<script type=\"text/javascript\" src=\"omi.js\"></script>" << std::endl
               <<   html::meta{"charset", "utf-8" }
               <<   html::title{report.layout.title}
               <<   html::src{"https://www.gstatic.com/charts/loader.js"}
               <<     javascript::google::compchart{report.delta_map, "chart"}
               << html::close{"head"}
               << html::tag{"body"}
               << html::tag{"header"}
               << html::h3{report.layout.header}
               << html::close{"header"}
               << html::sections{report.delta_map}
               << html::tag{"script"}
               <<   "document.getElementById(\"defaultOpen\").click();" << std::endl
               << html::close{"script"}
               << html::close{"body"}
               << html::tag{"footer"}
               <<   html::p{"&copy; " + report.layout.copyright, indent::two}
               << html::close{"footer"}
               << html::close{"html"};
}

} } }

#endif