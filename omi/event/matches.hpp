#ifndef OMI_EVENT_MATCHES_HPP_
#define OMI_EVENT_MATCHES_HPP_

#include <omi/event/match.hpp>
#include <omi/analysis/deltas.hpp>
#include <omi/source/write.hpp>

#include <vector>
#include <sstream>

// Matches 

namespace omi { 
namespace event {

template <class trigger, class response>
struct matches : std::vector<event::match<trigger, response>> {

    // Build list of deltas from matches
    auto deltas() const {
        std::vector<double> result(this->size());
        std::transform(this->begin(), this->end(), result.begin(), [](const auto &current) { return current.delta(); });
        return result;
    }


    // Build list of infos from matches
    auto infos() const {
        // To preallocate we need a cool way to make this default constructable
        std::vector<info<trigger, response>> result;
        for (const auto &match : *this) {
            result.push_back(match.info());
        }
        return result;
    }

    // Write infos to file
    void infos(const std::string &path) const {
        std::stringstream file; 
        for (const auto &info : infos()) { // template for this
            file << info << std::endl;
        }

        source::write(file.str(), path);
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