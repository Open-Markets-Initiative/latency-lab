#ifndef OMI_LATENCY_COMPARISON_TABS_HPP_
#define OMI_LATENCY_COMPARISON_TABS_HPP_

#include <omi/html/declarations.hpp>

#include <map>

// Generate multi-run latency comparison html tabs section

namespace omi { 
namespace latency {
namespace comparison {

struct tabs {

  //// Member Variables ///////////

    std::map<std::string, std::vector<double>> values_map; // remove this
};


// Stream operator (compose tab section) 
inline std::ostream &operator<<(std::ostream &out, const tabs &tabs) {
    // create tabs section
    out << "<div class=\"tab\">" << std::endl;
    out << "<button class=\"tablinks\" onclick=\"openTest(event, 'summary')\" id=\"defaultOpen\">Summary</button>" << std::endl; // todo make this an htmlclass that takes a list
    for (auto &&it : tabs.values_map) { // use array
        out << "<button class=\"tablinks\" onclick=\"openTest(event, '" + it.first + "')\">" + it.first + " Test</button>" << std::endl;
    }
    out << html::close{ "div" }
        << std::endl;
    return out;
}

} } }

#endif