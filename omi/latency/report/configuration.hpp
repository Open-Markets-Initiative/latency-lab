#ifndef OMI_LATENCY_REPORT_CONFIGURATION_HPP_
#define OMI_LATENCY_REPORT_CONFIGURATION_HPP_

#include <omi/types/period.hpp>
#include <boost/optional.hpp>
#include <string>

// Configuartion options for omi html latency report

namespace omi {
namespace latency {
namespace report {

struct configuration {
    std::string title;                          // Report html title
    std::string header;                         // Report header text
    std::string copyright;                      // Copyright text
    omi::period period;                         // Delta time period
    struct precision {
      boost::optional<size_t> chart{ 2 };       // Report chart precision
      boost::optional<size_t> statistics{ 2 };  // Report statistics precision
      boost::optional<size_t> percentiles{ 2 }; // Report percentiles precision
    } precision;
    std::string path;          // Html report output path
    // add note?

    std::string css;           // optional link to external css file 
};

// Stream operator
inline std::ostream &operator<<(std::ostream &out, const configuration &report) {
    return out << "  Title: " << report.title << std::endl
               << "  Header: " << report.header << std::endl
               << "  Period: " << report.period << std::endl;
}


} } }

#endif