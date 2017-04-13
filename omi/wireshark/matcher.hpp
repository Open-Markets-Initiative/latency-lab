#ifndef OMI_WIRESHARK_MATCHER_HPP_
#define OMI_WIRESHARK_MATCHER_HPP_

#include <omi/wireshark/events.hpp>
#include <omi/wireshark/database.hpp>
#include <omi/wireshark/matching.hpp>
#include <omi/wireshark/options.hpp>

    // Match wireshark events by id

namespace omi { 
namespace wireshark {

template <class inbound, class outbound>
struct matcher {

  //// Member Variables ///////////

    const database<inbound> inbounds;    // All possible inbound trigger events      
    const table<outbound> outbounds;     // Outbound response events
    const matching events;               // Matched events (need to template on events) and get a deltas

  //// Construction ///////////////

    // Construct from 2 file paths
    explicit matcher(const std::string &inbound_file, const std::string &outbound_file)
      : inbounds{ inbound_file }, outbounds{ outbound_file }, events{ match(inbounds, outbounds) } { }

    // Construct from matching inputs
    explicit matcher(const inputs &file)
      : inbounds{ file.inbound }, outbounds{ file.outbound }, events{ match(inbounds, outbounds) } { }

    // Construct from inbound and outbound events
    explicit matcher(const database<inbound> &inbounds, const table<outbound> &outbounds)
      : inbounds{ inbounds }, outbounds{ outbounds }, events{ match(inbounds, outbounds) } { }

  //// Implementation /////////////

    // Loop through outbound events and check if they match any inbound events
    static matching match(const database<inbound> &inbounds, const table<outbound> &outbounds) {
        matching results;
        for (const auto &response : outbounds.valids) {
            if (inbounds.has(response.identifier)) {
                auto trigger = inbounds.get(response.identifier);
                results.matches.push_back({ trigger, response });
            } else {
                results.misses.push_back(response);
            }
        }

        return results;
    }
};

// Stream operator
template <class inbound, class outbound>
inline std::ostream &operator<<(std::ostream &out, const matcher<inbound, outbound> &matcher) {
    return out << matcher.events;
}

} }

#endif
