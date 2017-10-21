#ifndef OMI_EVENT_MATCHES_HPP_
#define OMI_EVENT_MATCHES_HPP_

#include <omi/event/match.hpp>
#include <omi/analysis/deltas.hpp>
#include <omi/source/write.hpp>

#include <vector>
#include <algorithm>
#include <type_traits>

// Matches 

namespace omi { 
namespace event {

// transform vector acoording to operation (move this)
template<typename type, typename function>
std::vector<std::result_of_t<function(type)>> transform(const std::vector<type>& inputs, function operation) {
    std::vector<std::result_of_t<function(type)>> result(inputs.size());
    std::transform(inputs.begin(), inputs.end(), result.begin(), operation);
    return result;
}

template <typename trigger, typename response>
struct matches : std::vector<event::match<trigger, response>> {

    // Build list of matches times from matches
    auto timestamps() const {
        return transform(*this, [](const auto &current) { return current.timestamps(); });
    }

    // Build list of deltas from matches...need to move this out of here
    auto deltas() const {
        return transform(*this, [](const auto &current) { return current.timestamps().delta().microseconds(); });
    }

    // Build list of infos from matches
    auto infos() const {
        // To preallocate we need a cool way to make this default constructable
        // ...but that should not be a requirement, probably can add this to transform
        omi::match::infos<trigger, response> result;
        for (const auto &match : *this) {
            result.push_back(match.info());
        }
        return result;
      //  return transform(*this, [](const auto &current) { return current.info(); });
    }

  /////////////////////////////////

    // Write infos to file
    void infos(const std::string &path) const {
        source::write(infos(), path);
    }

    // Write timestamps to file
    void timestamps(const std::string &path) const {
        source::write(timestamps(), path);
    }

    // Write matches to file 
    void write(const std::string &path) const {
        source::write(*this, path);
    }
};

// Stream operator
template <typename trigger, typename response>
std::ostream &operator<<(std::ostream &out, const matches<trigger, response> &matches) {
    for (const auto &match : matches) {
        out << match << std::endl;
    }

    return out;
}

} }

#endif