#ifndef OMI_LATENCY_REPORT_LAYOUT_HPP_
#define OMI_LATENCY_REPORT_LAYOUT_HPP_

#include <omi/match/run.hpp>
#include <omi/table/statistics.hpp>
#include <omi/table/percentiles.hpp>
#include <omi/javascript/google/chart.hpp>
#include <omi/stylesheet/options.hpp>
#include <omi/source/write.hpp>
#include <omi/latency/report/configuration.hpp>

// Generate single run html latency report

namespace omi { 
namespace latency {
namespace report {

struct layout {

  //// Member Variables ///////////

    configuration options;      // Report layout options
    match::run run;             // Match run information

  //// Methods ////////////////////

    // Write html report to path
    void write(const std::string &path) const {
        source::write(*this, path);
    }
};

// Stream operator
inline std::ostream &operator<<(std::ostream &out, const layout &report) {
    return out << html::doctype{"html"}
               << html::tag{"html"}
               << std::endl
               << html::tag{"head"}
               <<   html::meta{"charset", "utf-8"}
               <<   html::title{report.options.title}
               <<   stylesheet::options{report.options.css}
               <<   html::src{"https://www.gstatic.com/charts/loader.js"}
               <<   html::script{"text/javascript"}
               <<     javascript::google::linechart{report.run.data, text(report.run.period), report.options.precision.chart.get(), "chart"}
               <<   html::close{"script"}
               << html::close{"head"}
               << std::endl
               << html::tag{"body"}
               << html::tag{"section"}
               <<   html::h3{report.options.header}
               <<   std::endl
               <<   html::tag{"article"}
               <<     html::div{"chart"}
               <<   html::close{"article"}
               <<   std::endl
               <<   html::tag{"article"}
               <<     html::h5{"Statistics"}
               <<     html::statistics{report.run.data, report.options.precision.statistics.get()}
               <<   html::close{"article"}
               <<   std::endl
               <<   html::tag{"article"}
               <<     html::h5{"Percentiles"}
               <<     html::percentiles{report.run.data, report.options.precision.percentiles.get()}
               <<   html::close{"article"}
               << html::close{"section"}
               << html::close{"body"}
               << std::endl
               << html::tag{"footer"}
               <<   html::p{"&copy; " + report.options.copyright, indent::two}
               << html::close{"footer"}
               << html::close{"html"};
}

} } }

#endif