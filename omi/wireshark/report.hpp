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
namespace report { // todo make a better name

struct options {
    std::string title;
    std::string header;
    std::string copyright;
    // add note
    std::string path;
};

struct data {
    std::string input;
    std::string output;
    std::vector<double> values;
};


inline void write(const options &options, const data &data) {
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
