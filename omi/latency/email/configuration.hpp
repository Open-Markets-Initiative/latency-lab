#ifndef OMI_LATENCY_EMAIL_CONFIGURATION_HPP_
#define OMI_LATENCY_EMAIL_CONFIGURATION_HPP_

#include <string>

// Configuartion options for omi html latency email

namespace omi::latency::email {

struct configuration {
    std::string title;             // Email html title
    std::string header;            // Header text
    std::string copyright;         // Copyright text
    omi::period period;            // Delta time period
    // add note?
};

}

#endif