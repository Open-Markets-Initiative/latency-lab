#ifndef OMI_LATENCY_RACE_CONFIGURATION_HPP_
#define OMI_LATENCY_RACE_CONFIGURATION_HPP_

#include <omi/types/period.hpp>
#include <string>

// Configuration options for omi html latency race

namespace omi { 
namespace latency {
namespace race {

struct configuration {
    std::string title;
    std::string header;
    std::string copyright;
    std::string css;
    omi::period period;                           // Delta time period
    struct precision {
        boost::optional<size_t> chart{ 2 };       // Report chart precision
        boost::optional<size_t> statistics{ 2 };  // Report statistics precision
        boost::optional<size_t> percentiles{ 2 }; // Report percentiles precision
    } precision;
    // add note?
};

// Stream operator
inline std::ostream &operator<<(std::ostream &out, const configuration &report) {
    return out << "  Title: " << report.title << std::endl
               << "  Header: " << report.header << std::endl
               << "  Period: " << report.period << std::endl;
}


} } }

#endif
