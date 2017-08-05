#ifndef OMI_LATENCY_COMPARISON_CONFIGURATION_HPP_
#define OMI_LATENCY_COMPARISON_CONFIGURATION_HPP_

#include <string>

// Configuration options for omi html latency comparison report

namespace omi { 
namespace latency {
namespace comparison {

struct configuration {
    std::string title;
    std::string header;
    std::string copyright;
    std::string css;
    // add note?
};

} } }

#endif
