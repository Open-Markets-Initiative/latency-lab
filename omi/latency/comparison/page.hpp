#ifndef OMI_LATENCY_COMPARISON_PAGE_HPP_
#define OMI_LATENCY_COMPARISON_PAGE_HPP_

#include <omi/html/declarations.hpp>
#include <omi/table/statistics.hpp>
#include <omi/table/percentiles.hpp>
#include <omi/match/run.hpp>

// Html report section contains graph, stat tables

namespace omi {
namespace latency {
namespace comparison {

struct page {
    // Member variables
    match::run run;
    omi::whitespace whitespace;

    // Standard constructor
    explicit page(const match::run &run, const indent whitespace = indent::none)
      : run{ run }, whitespace{ whitespace } {}
};

// Stream operator (prints chart and tables)
inline std::ostream &operator<<(std::ostream &out, const page &page) {
    return out << "<div id=\""+ page.run.name +"\" class=\"tabcontent\">" << std::endl
               << "<span onclick=\"this.parentElement.style.display='none'\" class=\"topright\">x</span>" << std::endl
               << html::tag{"section"}
               <<   html::h3{page.run.name}
               <<   std::endl
               <<   html::tag{"article"}
               <<     html::div{page.run.name + "chart"}
               <<   html::close{"article"}
               <<   std::endl
               <<   html::tag{"article"}
               <<     html::h5{"Statistics"}
               <<     html::statistics{page.run.data}
               <<   html::close{"article"}
               <<   std::endl
               <<   html::tag{"article"}
               <<     html::h5{"Percentiles"}
               <<     html::percentiles{page.run.data}
               <<   html::close{"article"}
               << html::close{"section"}
               << html::close{"div"};
}

} } }

#endif