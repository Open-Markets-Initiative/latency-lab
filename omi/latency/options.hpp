#ifndef OMI_LATENCY_REPORT_OPTIONS_HPP_
#define OMI_LATENCY_REPORT_OPTIONS_HPP_

#include <string>

// Options for omi html latency report

namespace omi { 
namespace latency {

struct options { // better name? layout
    std::string title;
    std::string header;
    std::string copyright;
    // add note?
};

} }

#endif
