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
    auto deltas() const {
        std::vector<double> result(this->size()); // template this
        std::transform(this->begin(), this->end(), result.begin(), [](const match<trigger, response>&current) { return current.delta(); });
        return result;
    }


    // Build list of infos from matches
    auto infos() const {
        std::vector<info<trigger, response>> result(this->size());;
        std::transform(this->begin(), this->end(), result.begin(), [](const match<trigger, response>&current) { return current.info(); });
        return result;
    }


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