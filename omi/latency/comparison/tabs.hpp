#ifndef OMI_LATENCY_COMPARISON_TABS_HPP_
#define OMI_LATENCY_COMPARISON_TABS_HPP_

#include <omi/html/declarations.hpp>

// Generate multi-run latency comparison html tabs section

namespace omi { 
namespace latency {
namespace comparison {

struct tabs {

  //// Member Variables ///////////

    match::runs runs; // remove this (better to provide list of names)
};


// Stream operator (compose tab section) 
inline std::ostream &operator<<(std::ostream &out, const tabs &tabs) {
    // create tabs section
    out << "<div class=\"tab\">" << std::endl;
    out << "<button class=\"tablinks\" onclick=\"openTest(event, 'summary')\" id=\"defaultOpen\">Summary</button>" << std::endl; // todo make this an htmlclass that takes a list
    for (auto &&run : tabs.runs) {
        out << "<button class=\"tablinks\" onclick=\"openTest(event, '" + run.name + "')\">" + run.name + "</button>" << std::endl;
    }
    out << html::close{ "div" }
        << std::endl;
    return out;
}

} } }

#endif