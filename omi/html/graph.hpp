#ifndef OMI_HTML_GRAPH_
#define OMI_HTML_GRAPH_

#include <omi/html/elements.hpp>

#include <iomanip>
#include <string>
#include <sstream>
#include <vector>

// Google graph element

namespace omi {
namespace html {

struct graph : html::element {

    // Selected chart points are removed to remain within google graph limits
    // ie, chart is not accurate.  This chart is for email that restricts use of javascript

    std::string whitespace;

    explicit graph(const std::vector<double> &values, indent whitespace = indent::none)
        : html::element{ "img", attribute{ "src", src(values) }, whitespace } {}

  /////////////////////////////////

    // Create src value for google graph img element 
    static std::string src(const std::vector<double> &values) {
        auto count = values.size();
        auto stride = graph::stride(count);

        std::stringstream src;
          src << "http://chart.apis.google.com/chart?chxt=x,y&amp;chxr=0,0," 
              << count << "&amp;chs=500x300&amp;cht=lc&amp;chds=a&amp;chd=t:";
        
        for (size_t index = 0; index < count; index += stride) {
            src << (index == 0 ? "" : ",") << std::fixed << std::setprecision(0) << values[index];
        }

        return src.str();
    }

    // Calculate stride...return a list of indexes
    static size_t stride(size_t count) {
        // This is crude...make a method that determines stride to always include 200 points
        return count >= 200 ? count / 200 : 1;
    }
};

// Stream operator (prints html google graph)
inline std::ostream &operator<<(std::ostream &out, const graph &graph) {
    return out << static_cast<html::element>(graph);
}

} }

#endif
