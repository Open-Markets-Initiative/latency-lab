#ifndef OMI_HTML_REPORT_HPP_
#define OMI_HTML_REPORT_HPP_

#include <omi/html/elements.hpp>
#include <omi/table/statistics.hpp>
#include <omi/table/percentiles.hpp>
#include <omi/javascript/google/chart.hpp>
#include <omi/styles/one.hpp>

#include <fstream>

// Generate single run html latency report

namespace omi { 
namespace html {

// make options?

inline void report(const std::vector<double> &values, const std::string &path) {
    // Verify output file
    std::ofstream stream(path);
    if (stream.bad()) {
        throw std::invalid_argument("Report output file invalid: " + path);
    }

    // print something different with no values?

    stream << html::doctype{"html"}
           << html::tag{"html"}
           << std::endl
           << html::tag{"head"}
           <<   html::meta{"charset", "utf-8" }
           <<   html::title{"OMI"} // This should be an option
           <<   html::src{"https://www.gstatic.com/charts/loader.js"}
           <<   html::script{"text/javascript"}
           <<     javascript::google::linechart{values, "chart"}
           <<   html::close{"script"}
           <<   html::tag{"style"}
           <<     css::one{} // make this an option
           <<   html::close{"style"}
           << html::close{"head"}
           << std::endl
           << html::tag{"body"}
           << html::tag{"section"}
           <<   html::h3{"Latency Example Run"} // This should be an option
           <<   std::endl
           <<   html::tag{"article"}
           <<     html::div{"chart"}
           <<   html::close{"article"}
           <<   std::endl
           <<   html::tag{"article"}
           <<     html::h5{"Statistics"}
           <<     html::statistics{values}
           <<   html::close{"article"}
           <<   std::endl
           <<   html::tag{"article"}
           <<     html::h5{"Percentiles"}
           <<     html::percentiles{values}
           <<   html::close{"article"}
           << html::close{"section"}
           << html::close{"body"}
           << std::endl
           << html::tag{"footer"}
           <<   html::p{"&copy; OMI. All rights reserved.", indent::two}
           << html::close{"footer"}
           << html::close{"html"};
}

} }

#endif
