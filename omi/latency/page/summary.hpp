#ifndef OMI_LATENCY_PAGE_SUMMARY_HPP_
#define OMI_LATENCY_COMPARISON_SUMMARY_HPP_

#include <omi/html/declarations.hpp>
#include <omi/match/runs.hpp>

// Generate multi-run latency comparison html summary section

namespace omi { 
namespace latency {
namespace page {

struct summary {

  //// Member Variables ///////////

    match::runs runs;
};

// Stream operator (composes html report from layout and data) 
inline std::ostream &operator<<(std::ostream &out, const summary &summary) {
    return out // need whitespace
        << html::tag{"div", html::attribute{ "id", "summary" }, html::attribute{ "class", "tabcontent" }}
        << html::element{"span", html::attribute{"onclick", "this.parentElement.style.display='none'" }, html::attribute{ "class", "topright" }, "x" }
        << html::tag{ "section" }
        <<   html::h3{ "Summary" }
        <<   html::element{ "article", "Click on tabs for run statistics" }
        << html::close{ "section" }
        << html::close{ "div" }
        << std::endl;
}

} } }

#endif