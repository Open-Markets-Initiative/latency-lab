#ifndef OMI_LATENCY_REPORT_CONFIGURATION_HPP_
#define OMI_LATENCY_REPORT_CONFIGURATION_HPP_

#include <string>

// Configuartion options for omi html latency report

namespace omi { 
namespace latency {
namespace report {

struct configuration {
    std::string title;
    std::string header;
    std::string copyright;
    // add note?
};

} } }

#endif
