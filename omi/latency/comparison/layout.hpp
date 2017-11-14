#ifndef OMI_LATENCY_COMPARISON_COMPONENTS_HPP_
#define OMI_LATENCY_COMPARISON_COMPONENTS_HPP_

#include <omi/table/statistics.hpp>
#include <omi/table/percentiles.hpp>
#include <omi/javascript/google/compchart.hpp>
#include <omi/source/write.hpp>
#include <omi/latency/comparison/configuration.hpp>
#include <omi/latency/comparison/summary.hpp>
#include <omi/latency/comparison/tabs.hpp>
#include <omi/latency/comparison/sections.hpp>

// Generate multi-run latency comparison html report

namespace omi { 
namespace latency {
namespace comparison {

struct layout {

  //// Member Variables ///////////

    comparison::configuration options;
    match::runs runs;

  //// Methods ////////////////////

    // Write html report to path
    void write(const std::string &path) const {
        source::write(*this, path);
    }
};


// Stream operator (composes html report from layout and data) 
inline std::ostream &operator<<(std::ostream &out, const layout &report) {
    return out << html::doctype{"html"}
               << html::tag{"html"}
               << std::endl
               << html::tag{"head"}
               << html::link{"stylesheet", "text/css", report.options.css}
               << html::src{"omi.js"}
               <<   html::meta{"charset", "utf-8" }
               <<   html::title{report.options.title}
                <<   html::src{"https://www.gstatic.com/charts/loader.js"}
               <<     javascript::google::charts{report.runs, "chart"} // this needs to be refactored
               << html::close{"head"}
               << html::tag{"body"}
               << html::tag{"header"}
               << html::h3{report.options.header}
               << html::close{"header"}
               << std::endl
               << tabs{report.runs}                    // This needs to be refactored
               << summary{ report.options, report.runs } // "
               << sections{report.runs}                  // "
               << html::tag{"script"}
               <<   "document.getElementById(\"defaultOpen\").click();" << std::endl
               << html::close{"script"}
               << html::close{"body"}
               << html::tag{"footer"}
               <<   html::p{"&copy; " + report.options.copyright, indent::two}
               << html::close{"footer"}
               << html::close{"html"};
}

} } }

#endif