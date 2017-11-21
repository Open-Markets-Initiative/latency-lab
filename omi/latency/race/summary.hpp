#ifndef OMI_LATENCY_RACE_SUMMARY_HPP_
#define OMI_LATENCY_RACE_SUMMARY_HPP_

#include <omi/html/declarations.hpp>
#include <omi/table/summary.hpp>
#include <omi/match/runs.hpp>

// Generate multi-run latency comparison html summary section

namespace omi { 
namespace latency {
namespace race {

struct summary {

  //// Member Variables ///////////

    match::runs runs;
};

// Stream operator
inline std::ostream &operator<<(std::ostream &out, const summary &summary) {
    // Add close x
    out << html::tag{"div", html::attribute{ "id", "summary" }, html::attribute{ "class", "tabcontent" }} // Make this one use results
        << html::element{"span", html::attribute{"onclick", "this.parentElement.style.display='none'" }, html::attribute{ "class", "topright" }, "x" };

    // Add summaries per run
    for (auto && run: summary.runs) {
    out << html::tag{ "section" }
        <<   html::summary{run.name, run.data}
        << html::close{ "section" };
    }

    // Add instructions
    out << html::tag{ "section" }
        <<   html::h3{ "Results" }
        <<   html::element{ "article", "Click on tabs for individual run result (UNDER CONSTRUCTION)" }
        << html::close{ "section" }
        << html::close{ "div" }
        << std::endl;

        return out;
}

} } }

#endif