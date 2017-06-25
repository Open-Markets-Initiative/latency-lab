#ifndef OMI_EVENT_MATCHER_HPP_
#define OMI_EVENT_MATCHER_HPP_

#include <omi/event/inputs.hpp>
#include <omi/event/database.hpp>
#include <omi/event/events.hpp>
#include <omi/event/matches.hpp>

// Match inbound and outbound events

namespace omi { 
namespace event {

template <class inbound, class outbound>
struct matcher {
    // Verify record id compatibility
    static_assert(is_matchable<inbound, outbound>, "Inbound and outbound records must use the same id() type");

  //// Member Variables ///////////

    matches<inbound, outbound> matched;    // Matched events
    std::vector<outbound> misses;          // Unmatched responses

  //// Construction ///////////////

    // Construct from 2 file paths (make these static)
    explicit matcher(const std::string &inbounds, const std::string &outbounds)
      : matcher{ database<inbound>::read(inbounds), responses<outbound>::read(outbounds) } {}

    // Construct from event inputs
    explicit matcher(const inputs &file)
      : matcher{ file.inbound, file.outbound } {}

    // Construct from events
    explicit matcher(const database<inbound> &inbounds, const responses<outbound> &outbounds) {
        for (const auto &response : outbounds.valids) {
            const auto trigger = inbounds.events.find(response.id());
            if (trigger != inbounds.events.end()) {
                matched.push_back(event::match<inbound, outbound>(trigger->second, response));
            } else {
                misses.push_back(response);
            }
        }
    }

  //// Methods ///////////////

};

// Stream operator
template <class inbound, class outbound>
std::ostream &operator<<(std::ostream &out, const matcher<inbound, outbound> &matcher) {
    return out << "  Matched: " << matcher.matched.size() << std::endl
               << "  Unmatched: " << matcher.misses.size() << std::endl;
}

} }

#endif