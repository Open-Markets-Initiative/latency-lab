#ifndef OMI_LATENCY_COMPARISON_PAGES_HPP_
#define OMI_LATENCY_COMPARISON_PAGES_HPP_

#include <omi/latency/comparison/page.hpp>
#include <omi/match/runs.hpp>

// Html report pages

namespace omi {
namespace latency {
namespace comparison {

struct pages {
    // Member variables
    match::runs runs;
    omi::whitespace whitespace;

    // Standard constructor
    explicit pages(const match::runs &runs, const indent whitespace = indent::none)
      : runs{ runs }, whitespace{ whitespace } {}
};

// Stream operator (prints chart and tables)
inline std::ostream &operator<<(std::ostream &out, const pages &report) {
    for (auto &&run: report.runs) {
        out << comparison::page{run};
    }

    return out;
}

} } }

#endif