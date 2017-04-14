#ifndef OMI_EVENT_MATCHES_HPP_
#define OMI_EVENT_MATCHES_HPP_

#include <omi/event/match.hpp>

#include <vector>
#include <sstream>
#include <omi/analysis/deltas.hpp>

// Matches 

namespace omi { 
namespace event {

template <class trigger, class response>
struct matches : std::vector<event::match<trigger, response>> {

    // Build list of deltas from matches
    analysis::deltas values() const {  // use transform
        analysis::deltas deltas;
        for (const auto &match : *this) {
            deltas.push_back(match.delta());
        }
        return deltas;
    }

    // make one called events...need better names

    // Build list of delta times from matches
    std::vector<double> deltas() const { // use transform
        std::vector<double> result;
        // result.reserve(*this.size()); figure out how to reserve
        for (const auto &match : *this) {
            result.push_back(match.time());
        }
        return result;
    }

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
