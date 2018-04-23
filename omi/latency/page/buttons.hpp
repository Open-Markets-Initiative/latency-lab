#ifndef OMI_LATENCY_PAGE_BUTTONS_HPP_
#define OMI_LATENCY_PAGE_BUTTONS_HPP_

#include <omi/html/declarations.hpp>
#include <omi/match/runs.hpp>

// Generate multi-run latency comparison html tabs section

namespace omi {
namespace latency {
namespace page {

struct buttons {

  //// Member Variables ///////////

    match::runs runs; // (better to provide list of names)
};

// Stream operator (compose tab section) 
inline std::ostream &operator<<(std::ostream &out, const buttons &buttons) {
    // create tabs section
    out << "<div class=\"tab\">" << std::endl;
    out << "<button class=\"tablinks\" onclick=\"select(event, 'summary')\" id=\"defaultOpen\">Summary</button>" << std::endl; // todo make this an htmlclass that takes a list
    for (auto &&run : buttons.runs) {
        out << "<button class=\"tablinks\" onclick=\"select(event, '" + run.name + "')\">" + run.name + "</button>" << std::endl;
    }
    out << html::close{ "div" }
        << std::endl;
    return out;
}

} } }

#endif