#ifndef OMI_LATENCY_COMPARISON_CONFIGURATION_HPP_
#define OMI_LATENCY_COMPARISON_CONFIGURATION_HPP_

#include <string>
#include <optional>

// Configuration options for omi html latency comparison report

namespace omi::latency::comparison {

struct configuration {
    std::string title;                            // Report title
    std::string header;                           // Report header
    std::string copyright;                        // Report copyright
    std::string css;                              // Report css
    omi::period period;                           // Delta time period
    struct precision {
        std::optional<size_t> chart{ 2 };         // Report chart precision
        std::optional<size_t> statistics{ 2 };    // Report statistics precision
        std::optional<size_t> percentiles{ 2 };   // Report percentiles precision
    } precision;
    // add note?
};

// Stream operator
inline std::ostream &operator<<(std::ostream &out, const configuration &report) {
    return out << "  Title: " << report.title << std::endl
               << "  Header: " << report.header << std::endl
               << "  Period: " << report.period << std::endl;
}

}

#endif
