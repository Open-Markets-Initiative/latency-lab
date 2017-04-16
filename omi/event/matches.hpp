#ifndef OMI_EVENT_MATCHES_HPP_
#define OMI_EVENT_MATCHES_HPP_

#include <omi/event/match.hpp>
#include <omi/analysis/deltas.hpp>
#include <omi/source/write.hpp>

#include <vector>

// Matches 

namespace omi { 
namespace event {

template <class trigger, class response>
struct matches : std::vector<event::match<trigger, response>> {

    // Build list of delta times from matches
    std::vector<double> deltas() const { // use transform
        std::vector<double> result; // TODO: figure out how to reserve
        for (const auto &match : *this) {
            result.push_back(match.delta()); // make a way to template precision
        }

        return result;
    }

/*
    // Make one called infos...need better names
    analysis::deltas info() const {
        analysis::deltas deltas;
        for (const auto &match : *this) {
            deltas.push_back(match.delta());
        }
        return deltas;
    }
*/

    // Write matches to file 
    void write(const std::string &path) const {
        source::write(*this, path);
    }
};

// Stream operator
template <class trigger, class response>
std::ostream &operator<<(std::ostream &out, const matches<trigger, response> &matches) {
    for (const auto &match : matches) {
        out << match << std::endl;
    }

    return out;
}

} }

#endif