#ifndef OMI_LATENCY_REPORT_CONFIGURATION_HPP_
#define OMI_LATENCY_REPORT_CONFIGURATION_HPP_

#include <string>

// Configuartion options for omi html latency report

namespace omi { 
namespace latency {
namespace report {

struct configuration {
    std::string title;         // Report html title
    std::string header;        // Report header text
    std::string copyright;     // Copyright text
    // add note?

	std::string css;           // optional link to external css file 
};

} } }

#endif