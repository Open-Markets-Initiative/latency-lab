#ifndef OMI_LATENCY_RACE_LAYOUT_HPP_
#define OMI_LATENCY_RACE_LAYOUT_HPP_

#include <omi/latency/race/configuration.hpp>
#include <omi/latency/race/summary.hpp>
#include <omi/latency/page/charts.hpp>
#include <omi/latency/page/buttons.hpp>
#include <omi/latency/page/pages.hpp>
#include <omi/javascript/paging.hpp>
#include <omi/source/write.hpp>

// Generate multi-run latency race 

namespace omi { 
namespace latency {
namespace race {

struct layout {

  //// Member Variables ///////////

    race::configuration options;
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
               <<   html::link{"stylesheet", "text/css", report.options.css}
               <<   html::meta{"charset", "utf-8" }
               <<   html::title{report.options.title}
               <<   html::src{ "https://www.gstatic.com/charts/loader.js" }
               <<   html::script{"text/javascript"}
               <<     page::charts{report.runs} 
               <<     javascript::paging{}
               <<   html::close{ "script" }
               << html::close{"head"}
               << std::endl
               << html::tag{"body"}
               << html::tag{"header"}
               <<   html::h3{report.options.header}
               << html::close{"header"}
               << std::endl
               <<   page::buttons{report.runs} // move this to javascript
               <<   race::summary{report.runs}
               <<   page::pages{report.runs}
               << html::tag{"script"}
               <<   "document.getElementById(\"defaultOpen\").click();" << std::endl // Method for this? Does it have to go here?
               << html::close{"script"}
               << html::close{"body"}
               << std::endl
               << html::tag{"footer"}
               <<   html::p{"&copy; " + report.options.copyright, indent::two}
               << html::close{"footer"}
               << html::close{"html"};
}

} } }

#endif