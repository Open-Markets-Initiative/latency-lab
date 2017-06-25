#ifndef OMI_HTML_SECTIONS_HPP_
#define OMI_HTML_SECTIONS_HPP_

#include <omi/analysis/statistics.hpp>
#include <omi/analysis/percentile.hpp>
#include <omi/html/declarations.hpp>

// Html test section. contains graph, stat tables

namespace omi {
namespace html {

struct sections {

    // this will create chart and tables for each test

    // check Member variables
    //analysis::statistics standard; // Standard statistics
    //analysis::statistics steady;   // Steady state statistics
    std::map<std::string, std::vector<double>> values_map;
    omi::whitespace whitespace;

    // Standard constructor
    explicit sections(const std::map<std::string,std::vector<double>> &values_map,
                   indent whitespace = indent::none)
            : values_map{values_map}, whitespace { whitespace } {}
};

// Stream operator (prints chart and tables)
inline std::ostream &operator<<(std::ostream &out, const sections &secs) {

        // create tabs
        out << "<div class=\"tab\">" << std::endl;

        auto first_rec = true;
        for (auto &&it: secs.values_map) {
            if (first_rec) {
                out << "<button class=\"tablinks\" onclick=\"openTest(event, '"+ it.first +"')\" id=\"defaultOpen\">"+
                        it.first +" Test</button>" << std::endl;
            } else {
                out << "<button class=\"tablinks\" onclick=\"openTest(event, '"+ it.first +"')\">"+
                        it.first +" Test</button>" << std::endl;
            }

            first_rec = false;
        }
        out << html::close{"div"};

        // tab content
    for (auto &&it: secs.values_map) {

        std::string report_name = it.first;
        std::vector<double> values = it.second;

        out << "<div id=\""+ report_name +"\" class=\"tabcontent\">" << std::endl
            << "<span onclick=\"this.parentElement.style.display='none'\" class=\"topright\">x</span>" << std::endl
            << html::tag{"section"}
            << html::h3{report_name}
            << std::endl
            << html::tag{"article"}
            << html::div{"chart_" + report_name}
            << html::close{"article"}
            << std::endl
            << html::tag{"article"}
            << html::h5{"Statistics"}
            << html::statistics{values}
            << html::close{"article"}
            << std::endl
            << html::tag{"article"}
            << html::h5{"Percentiles"}
            << html::percentiles{values}
            << html::close{"article"}
            << html::close{"section"}
            << html::close{"div"};
    }

        return out;
}

} }

#endif
