#ifndef OMI_HTML_PERCENTILES_HPP_
#define OMI_HTML_PERCENTILES_HPP_

#include <omi/analysis/percentiles.hpp>
#include <omi/html/declarations.hpp>

// Html table of common statistics

namespace omi {
namespace html {

struct percentiles {
    // Memeber Variables
    analysis::percentiles percents;
    omi::whitespace whitespace;

    // Standard constructor
    explicit percentiles(const std::vector<double> &values, indent whitespace = indent::none)
        : percents{ values }, whitespace{ whitespace } {}
};

// Stream operator (build html horizontal table for displaying percentiles)
inline std::ostream &operator<<(std::ostream &out, const percentiles &table) {
    return out << table.whitespace << html::table{"gridtable"}
               << table.whitespace << html::tag{"tr"}
               << table.whitespace <<   html::element{"th", "100%", indent::two}
               << table.whitespace <<   html::element{"th", "99%", indent::two}
               << table.whitespace <<   html::element{"th", "90%", indent::two}
               << table.whitespace <<   html::element{"th", "75%", indent::two}
               << table.whitespace <<   html::element{"th", "50%", indent::two}
               << table.whitespace <<   html::element{"th", "25%", indent::two}
               << table.whitespace <<   html::element{"th", "10%", indent::two}
               << table.whitespace <<   html::element{"th", "1%", indent::two}
               << table.whitespace <<   html::element{"th", "0%", indent::two}
               << table.whitespace << html::close{"tr"}
               << table.whitespace << html::tag{"tr"}
               << table.whitespace <<   html::open{"td", indent::two} << table.percents.p100 << html::close{"td"}
               << table.whitespace <<   html::open{"td", indent::two} << table.percents.p99 << html::close{"td"}
               << table.whitespace <<   html::open{"td", indent::two} << table.percents.p90 << html::close{"td"}
               << table.whitespace <<   html::open{"td", indent::two} << table.percents.p75 << html::close{"td"}
               << table.whitespace <<   html::open{"td", indent::two} << table.percents.p50 << html::close{"td"}
               << table.whitespace <<   html::open{"td", indent::two} << table.percents.p25 << html::close{"td"}
               << table.whitespace <<   html::open{"td", indent::two} << table.percents.p10 << html::close{"td"}
               << table.whitespace <<   html::open{"td", indent::two} << table.percents.p01 << html::close{"td"}
               << table.whitespace <<   html::open{"td", indent::two} << table.percents.p00 << html::close{"td"}
               << table.whitespace << html::close{"tr"}
               << table.whitespace << html::close{"table"};
}

} }

#endif
