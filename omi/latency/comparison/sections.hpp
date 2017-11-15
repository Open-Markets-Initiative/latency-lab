#ifndef OMI_LATENCY_COMPARISON_SECTIONS_HPP_
#define OMI_LATENCY_COMPARISON_SECTIONS_HPP_

#include <omi/html/declarations.hpp>
#include <omi/table/statistics.hpp>
#include <omi/table/percentiles.hpp>
#include <omi/match/runs.hpp>

// Html report sections contains graph, stat tables

namespace omi {
namespace latency {
namespace comparison {

// this will create chart and tables for each test
struct sections {
    // check Member variables
    match::runs runs; // Need to break this up and loop outside this class
    omi::whitespace whitespace;

    // Standard constructor
    explicit sections(const match::runs &runs, const indent whitespace = indent::none)
      : runs{ runs }, whitespace{ whitespace } {}
};

// Stream operator (prints chart and tables)
inline std::ostream &operator<<(std::ostream &out, const sections &secs) {
    for (auto &&run: secs.runs) {
        out << "<div id=\""+ run.name +"\" class=\"tabcontent\">" << std::endl
            << "<span onclick=\"this.parentElement.style.display='none'\" class=\"topright\">x</span>" << std::endl
            << html::tag{"section"}
            <<   html::h3{run.name}
            << std::endl
            << html::tag{"article"}
            <<   html::div{run.name + "chart"}
            <<   html::close{"article"}
            << std::endl
            << html::tag{"article"}
            <<   html::h5{"Statistics"}
            <<   html::statistics{run.data}
            << html::close{"article"}
            << std::endl
            << html::tag{"article"}
            <<   html::h5{"Percentiles"}
            <<   html::percentiles{run.data}
            <<   html::close{"article"}
            << html::close{"section"}
            << html::close{"div"};
    }

    return out;
}

} } }

#endif