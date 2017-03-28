#ifndef OMI_LATENCY_REPORT_OPTIONS_HPP_
#define OMI_LATENCY_REPORT_OPTIONS_HPP_

#include <string>
#include <vector>

// Options for omi latncy report

namespace omi { 
namespace latency {
namespace report { // todo make a better name

struct options {
    std::string title;
    std::string header;
    std::string copyright;
    // add note
    std::string path;
};

struct data {
    std::string input;
    std::string output;
    std::vector<double> values;
};

} } }

#endif
