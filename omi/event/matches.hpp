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

// Transform vector acoording to operation (move this)
template<typename type, typename function>
auto transform(const std::vector<type>& inputs, function operation) {
    std::vector<std::result_of_t<function(type)>> result(inputs.size());
    std::transform(inputs.begin(), inputs.end(), result.begin(), operation);
    return result;
} // make one that decides default constructability at compiletime

// Stream out all elements in a container 
template<typename container>
auto out(std::ostream &out, const container &elements) {
    for (const auto &element : elements) {
        out << element << std::endl;
    }

    return out;
}


template <typename trigger, typename response>
struct matches : std::vector<event::match<trigger, response>> {

    // Returns a list of matched timestamps
    auto timestamps() const {
        return transform(*this, [](const auto &current) { return current.timestamps(); });
    }

    // Returns a list of deltas from matched timestamps
    auto deltas() const {
        return transform(*this, [](const auto &current) { return current.timestamps().delta(); });
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
std::ostream &operator<<(std::ostream &stream, const matches<trigger, response> &matches) {
    return out(stream, matches);
}

} }

#endif