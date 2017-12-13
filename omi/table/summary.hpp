#ifndef OMI_HTML_SUMMARY_HPP_
#define OMI_HTML_SUMMARY_HPP_

#include <omi/analysis/summary.hpp>
#include <omi/sequence/range.hpp>
#include <omi/html/declarations.hpp>

#include <iomanip>

// Html table of common latency summay statistics

namespace omi {
namespace html {

struct summary {
    // Member variables
    std::string name;             // Name
    analysis::summary<> standard; // Standard statistics
    analysis::summary<> steady;   // Steady state statistics
    size_t precision;             // Table precision
    omi::whitespace whitespace;

    // Standard constructor
    explicit summary(const std::string &name, const std::vector<double> &values, const size_t precision = 4, indent whitespace = indent::none)
      : name{ name},
        standard{ values},
        steady{ sequence::range(values, 0, 70)}, // make this take values directly
        precision{ precision },
        whitespace{ whitespace } {}
};

// Stream operator
inline std::ostream &operator<<(std::ostream &out, const summary &table) {
    return out << std::fixed << std::setprecision(table.precision)
               << table.whitespace << html::table{ "gridtable" }
               << table.whitespace << html::tag{"tr"}
               << table.whitespace <<   html::element{"th", table.name, indent::two}
               << table.whitespace <<   html::element{"th", "Average", indent::two}
               << table.whitespace <<   html::element{"th", "Std Dev", indent::two}
               << table.whitespace <<   html::element{"th", "Minimum", indent::two}
               << table.whitespace <<   html::element{"th", "Maximum", indent::two}
               << table.whitespace <<   html::element{"th", "Events", indent::two }
               << table.whitespace << html::close{"tr"}
               << table.whitespace << html::tag{"tr"}
               << table.whitespace <<   html::element{"td", "Standard", indent::two }
               << table.whitespace <<   html::open{"td", indent::two} << table.standard.average << html::close{"td"}
               << table.whitespace <<   html::open{"td", indent::two} << table.standard.deviation << html::close{"td"}
               << table.whitespace <<   html::open{"td", indent::two} << table.standard.minimum << html::close{"td"}
               << table.whitespace <<   html::open{"td", indent::two} << table.standard.maximum << html::close{"td"}
               << table.whitespace <<   html::open{"td", indent::two} << table.standard.count << html::close{ "td" }
               << table.whitespace << html::close{"tr"}
               << table.whitespace << html::tag{"tr"}
               << table.whitespace << html::element{"td", "Steady State", indent::two}
               << table.whitespace <<   html::open{"td", indent::two} << table.steady.average << html::close{"td"}
               << table.whitespace <<   html::open{"td", indent::two} << table.steady.deviation << html::close{"td"}
               << table.whitespace <<   html::open{"td", indent::two} << table.steady.minimum << html::close{"td"}
               << table.whitespace <<   html::open{"td", indent::two} << table.steady.maximum << html::close{"td"}
               << table.whitespace <<   html::open{"td", indent::two} << table.steady.count << html::close{"td"}
               << table.whitespace << html::close{"tr"}
               << table.whitespace << html::close{"table"};
}

} }

#endif