#ifndef OMI_LATENCY_REPORT_COMPONENTS_HPP_
#define OMI_LATENCY_REPORT_COMPONENTS_HPP_

#include <omi/table/statistics.hpp>
#include <omi/table/percentiles.hpp>
#include <omi/javascript/google/chart.hpp>
#include <omi/stylesheet/options.hpp>
#include <omi/source/write.hpp>
#include <omi/latency/report/configuration.hpp>
#include <omi/match/inputs.hpp>
#include <omi/match/results.hpp>

// Generate single run html latency report

namespace omi { 
namespace latency {
namespace report {

template<typename container = std::vector<double>>
struct components {

  //// Member Variables ///////////

    configuration layout;  // Report layout options
    match::inputs files;   // Input files
    container data;        // Ordered event times

  //// Methods ////////////////////

    // Write html report to path
    void write(const std::string &path) const {
        source::write(*this, path);
    }
};

// Microseconds functor
template <typename inbound, typename outbound>
struct microseconds {
    using type = match::timestamps<inbound, outbound>;
    auto operator()(const type& current) { return current.delta().microseconds(); }
};

// Microseconds functor
template<typename inbound, typename outbound, typename period = microseconds<inbound, outbound>> // add functor
auto generate(const configuration config, match::result<inbound, outbound> result) {
    using container = std::vector<double>; // need to get this from functor
    components<container> report;
      report.layout = config;
      report.files = result.path;
      report.data = event::transform(result.data.matched.timestamps(), period());

    return report;
};

// Stream operator
template<typename container>
inline std::ostream &operator<<(std::ostream &out, const components<container> &report) {
    return out << html::doctype{"html"}
               << html::tag{"html"}
               << std::endl
               << html::tag{"head"}
               <<   html::meta{"charset", "utf-8"}
               <<   html::title{report.layout.title}
               <<   stylesheet::options{report.layout.css}
               <<   html::src{"https://www.gstatic.com/charts/loader.js"}
               <<   html::script{"text/javascript"}
               <<     javascript::google::linechart{report.data, "chart"}
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
               <<     html::statistics{report.data}
               <<   html::close{"article"}
               <<   std::endl
               <<   html::tag{"article"}
               <<     html::h5{"Percentiles"}
               <<     html::percentiles{report.data}
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