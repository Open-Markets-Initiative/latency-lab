#ifndef OMI_LATENCY_REPORT_COMPONENTS_HPP_
#define OMI_LATENCY_REPORT_COMPONENTS_HPP_

#include <omi/table/statistics.hpp>
#include <omi/table/percentiles.hpp>
#include <omi/javascript/google/chart.hpp>
#include <omi/stylesheet/options.hpp>
#include <omi/source/write.hpp>
#include <omi/match/inputs.hpp>
#include <omi/latency/report/configuration.hpp>

// Generate single run html latency report

namespace omi { 
namespace latency {
namespace report {

struct components {

  //// Member Variables ///////////

    configuration layout;          // Report layout options
    match::inputs files;           // Input files
    std::vector<double> data;      // Ordered event times

  //// Methods ////////////////////

    // Write html report to path
    void write(const std::string &path) const {
        source::write(*this, path);
    }
};

// Stream operator
inline std::ostream &operator<<(std::ostream &out, const components &report) {
    return out << html::doctype{"html"}
               << html::tag{"html"}
               << std::endl
               << html::tag{"head"}
               <<   html::meta{"charset", "utf-8"}
               <<   html::title{report.layout.title}
               <<   stylesheet::options{report.layout.css}
               <<   html::src{"https://www.gstatic.com/charts/loader.js"}
               <<   html::script{"text/javascript"}
               <<     javascript::google::linechart{report.data, text(report.layout.period), report.layout.precision.chart.get(), "chart"}
               <<   html::close{"script"}
               << html::close{"head"}
               << std::endl
               << html::tag{"body"}
               << html::tag{"section"}
               <<   html::h3{report.layout.header}
               <<   std::endl
               <<   html::tag{"article"}
               <<     html::div{"chart"}
               <<   html::close{"article"}
               <<   std::endl
               <<   html::tag{"article"}
               <<     html::h5{"Statistics"}
               <<     html::statistics{report.data, report.layout.precision.statistics.get()}
               <<   html::close{"article"}
               <<   std::endl
               <<   html::tag{"article"}
               <<     html::h5{"Percentiles"}
               <<     html::percentiles{report.data, report.layout.precision.percentiles.get()}
               <<   html::close{"article"}
               << html::close{"section"}
               << html::close{"body"}
               << std::endl
               << html::tag{"footer"}
               <<   html::p{"&copy; " + report.layout.copyright, indent::two}
               << html::close{"footer"}
               << html::close{"html"};
}

} } }

#endif