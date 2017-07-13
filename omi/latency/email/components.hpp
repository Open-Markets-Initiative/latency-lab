#ifndef OMI_LATENCY_EMAIL_COMPONENTS_HPP_
#define OMI_LATENCY_EMAIL_COMPONENTS_HPP_

#include <omi/table/statistics.hpp>
#include <omi/table/percentiles.hpp>
#include <omi/html/graph.hpp>
#include <omi/stylesheet/standard.hpp>
#include <omi/source/write.hpp>
#include <omi/event/inputs.hpp>
#include <omi/latency/email/configuration.hpp>


// Generate single run html latency report

namespace omi { 
namespace latency {
namespace email {

struct components {

  //// Member Variables ///////////

    email::configuration layout;   // Common layout options
    event::inputs files;           // Input files
    std::vector<double> data;      // Ordered event times

  //// Methods ////////////////////

    // Write html report to path
    void write(const std::string &path) const {
        source::write(*this, path);
    }
};

// Stream operator (composes html email from layout and data) 
inline std::ostream &operator<<(std::ostream &out, const components &email) {
    return out << html::doctype{"html"}
               << html::tag{"html"}
               << std::endl
               << html::tag{"head"}
               <<   html::meta{"charset", "utf-8" }
               <<   html::title{email.layout.title}
               <<   html::tag{"style"}
               <<     stylesheet::standard{} // TODO: Make this an option
               <<   html::close{"style"}
               << html::close{"head"}
               << std::endl
               << html::tag{"body"}
               << html::tag{"section"}
               <<   html::h3{email.layout.header}
               <<   std::endl
               <<   html::tag{"article"}
               <<     html::graph{email.data}
               <<   html::close{"article"}
               <<   std::endl
               <<   html::tag{"article"}
               <<     html::h5{"Statistics"}
               <<     html::statistics{email.data}
               <<   html::close{"article"}
               <<   std::endl
               <<   html::tag{"article"}
               <<     html::h5{"Percentiles"}
               <<     html::percentiles{email.data}
               <<   html::close{"article"}
               << html::close{"section"}
               << html::close{"body"}
               << std::endl
               << html::tag{"footer"}
               <<   html::p{"&copy; " + email.layout.copyright, indent::two}
               << html::close{"footer"}
               << html::close{"html"};
}

} } }

#endif