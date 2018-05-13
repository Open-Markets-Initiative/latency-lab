#ifndef OMI_HTML_STATISTICS_HPP_
#define OMI_HTML_STATISTICS_HPP_

#include <iomanip>

#include <omi/analysis/statistics.hpp>
#include <omi/collection/range.hpp>
#include <omi/html/declarations.hpp>

// Html table of common latency statistics

namespace omi {
namespace html {

struct statistics {
    // Member variables
    analysis::statistics<> standard; // Standard statistics
    analysis::statistics<> steady;   // Steady state statistics
    size_t precision;                // Table precision
    omi::whitespace whitespace;

    // Standard constructor
    explicit statistics(const std::vector<double> &values, const size_t precision = 4, indent whitespace = indent::none)
      : standard{ values},
        steady{ collection::range(values, 0, 70)}, // make this take values directly
        precision{precision},
        whitespace { whitespace } {}
};

// Stream operator
inline std::ostream &operator<<(std::ostream &out, const statistics &table) {
    return out << std::fixed << std::setprecision(table.precision)
               << table.whitespace << html::table{ "gridtable" }
               << table.whitespace << html::tag{"tr"}
               << table.whitespace <<   html::element{"th", indent::two }
               << table.whitespace <<   html::element{"th", "Standard", indent::two }
               << table.whitespace <<   html::element{"th", "Steady State", indent::two }
               << table.whitespace << html::close{"tr"}
               << table.whitespace << html::tag{"tr"}
               << table.whitespace <<   html::element{"td", "Average", indent::two}
               << table.whitespace <<   html::open{"td", indent::two} << table.standard.average << html::close{"td"}
               << table.whitespace <<   html::open{"td", indent::two} << table.steady.average << html::close{"td"}
               << table.whitespace << html::close{"tr"}
               << table.whitespace << html::tag{"tr"}
               << table.whitespace <<   html::element{"td", "Standard Deviation", indent::two}
               << table.whitespace <<   html::open{"td", indent::two } << table.standard.deviation << html::close{"td"}
               << table.whitespace <<   html::open{"td", indent::two } << table.steady.deviation << html::close{"td"}
               << table.whitespace << html::close{"tr"}
               << table.whitespace << html::tag{"tr"}
               << table.whitespace <<   html::element{"td", "Events", indent::two}
               << table.whitespace <<   html::open{"td", indent::two } << table.standard.count << html::close{"td"}
               << table.whitespace <<   html::open{"td", indent::two } << table.steady.count << html::close{"td"}
               << table.whitespace << html::close{"tr"}
               << table.whitespace << html::close{"table"};
}

} }

#endif