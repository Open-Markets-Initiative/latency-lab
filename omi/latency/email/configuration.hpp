#ifndef OMI_LATENCY_EMAIL_CONFIGURATION_HPP_
#define OMI_LATENCY_EMAIL_CONFIGURATION_HPP_

#include <string>

// Configuartion options for omi html latency email

namespace omi { 
namespace latency {
namespace email {

struct configuration {
    std::string title;
    std::string header;
    std::string copyright;
    // add note?
};

} } }

#endif