#ifndef OMI_LATENCY_REPORT_HPP_
#define OMI_LATENCY_REPORT_HPP_

#include <omi/table/statistics.hpp>
#include <omi/table/percentiles.hpp>
#include <omi/javascript/google/chart.hpp>
#include <omi/styles/one.hpp>
#include <omi/latency/options.hpp>

#include <fstream>

// Generate single run html latency report

namespace omi { 
namespace latency {
namespace report {

inline void write(const report::options &options, const report::data &data) {
    // Verify output file
    std::ofstream stream(options.path);
    if (stream.bad()) {
        throw std::invalid_argument("Report output file invalid: " + options.path);
    }

    // Print something different with no values?

    stream << html::doctype{"html"}
           << html::tag{"html"}
           << std::endl
           << html::tag{"head"}
           <<   html::meta{"charset", "utf-8" }
           <<   html::title{options.title}
           <<   html::src{"https://www.gstatic.com/charts/loader.js"}
           <<   html::script{"text/javascript"}
           <<     javascript::google::linechart{data.values, "chart"}
           <<   html::close{"script"}
           <<   html::tag{"style"}
           <<     css::one{} // make this an option
           <<   html::close{"style"}
           << html::close{"head"}
           << std::endl
           << html::tag{"body"}
           << html::tag{"section"}
           <<   html::h3{options.header}
           <<   std::endl
           <<   html::tag{"article"}
           <<     html::div{"chart"}
           <<   html::close{"article"}
           <<   std::endl
           <<   html::tag{"article"}
           <<     html::h5{"Statistics"}
           <<     html::statistics{data.values}
           <<   html::close{"article"}
           <<   std::endl
           <<   html::tag{"article"}
           <<     html::h5{"Percentiles"}
           <<     html::percentiles{data.values}
           <<   html::close{"article"}
           << html::close{"section"}
           << html::close{"body"}
           << std::endl
           << html::tag{"footer"}
           <<   html::p{"&copy; " + options.copyright, indent::two}
           << html::close{"footer"}
           << html::close{"html"};
}

} } }

#endif
