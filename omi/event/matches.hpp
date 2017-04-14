#ifndef OMI_EVENT_MATCHES_HPP_
#define OMI_EVENT_MATCHES_HPP_

#include <omi/event/match.hpp>

#include <vector>
#include <sstream>

// Matches 

namespace omi { 
namespace event {

template <class trigger, class response>
struct matches : std::vector<event::match<trigger, response>> {

    // Write vector to file 
    void write(const std::string &file) const {
        // Verify file
        std::ofstream stream(file.c_str());
        if (stream.bad()) {
            throw std::invalid_argument("Invalid matches file: " + file);
        }

        stream << output();
        stream.close();
    }

    // Add matches to stream
    std::string output() const {
        std::stringstream stream;
        for (const auto &match : *this) {
            stream << match << std::endl;
        }

        return stream.str();
    }
};

// Stream operator
template <class trigger, class response>
std::ostream &operator<<(std::ostream &out, const matches<trigger, response> &matches) {
    return out << matches.output();
}

} }

#endif
