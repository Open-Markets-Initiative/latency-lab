#ifndef OMI_EVENT_MATCHES_HPP_
#define OMI_EVENT_MATCHES_HPP_

#include <omi/event/match.hpp>
#include <omi/source/write.hpp>
#include <omi/collection/transform.hpp>
#include <omi/collection/out.hpp>
#include <omi/types/period.hpp>

// Matches

namespace omi::event {

template <typename trigger, typename response>
struct matches : std::vector<event::match<trigger, response>> {

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

    // Returns a list of matched timestamps
    auto timestamps() const {
        return transform(*this, [](const auto &current) { return current.timestamps(); });
    }

    // Returns a list of deltas timespans  from matched timestamps
    auto deltas() const {
        return transform(*this, [](const auto &current) { return current.timestamps().delta(); });
    }

    // Returns a list of delta values based on period
    auto deltas(const period period) const {
        switch (period) {
        case period::nanosecond:
            return collection::transform(*this, [](const auto & current) { return current.timestamps().delta().nanoseconds(); });
        case period::microsecond:
            return collection::transform(*this, [](const auto & current) { return current.timestamps().delta().microseconds(); });
        case period::millisecond:
            return collection::transform(*this, [](const auto & current) { return current.timestamps().delta().milliseconds(); });
        case period::second:
            return collection::transform(*this, [](const auto & current) { return current.timestamps().delta().seconds(); });
        case period::minute:
            return collection::transform(*this, [](const auto & current) { return current.timestamps().delta().minutes(); });
        default:
            throw std::invalid_argument("Not implemented");
        }
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
    return collection::stream(out, matches);
}

}

#endif