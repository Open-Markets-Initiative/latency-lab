#ifndef OMI_EVENT_MATCHER_HPP_
#define OMI_EVENT_MATCHER_HPP_

#include <omi/event/database.hpp>
#include <omi/event/events.hpp>
#include <omi/event/matches.hpp>
#include <omi/event/inputs.hpp>

// Match inbound and outbound events

namespace omi { 
namespace event {

template <class inbound, class outbound>
struct matcher {

  //// Member Variables ///////////

    const database<inbound> &inbounds;        // Inbound events database
    const responses<outbound> &outbounds;     // Outbound response events
	matches<inbound, outbound> matches;    // Matches
	std::vector<outbound> misses;                    // Outbound repsonses without matching inbound event

  //// Construction ///////////////

    // Construct from 2 file paths
    explicit matcher(const std::string &inbound_file, const std::string &outbound_file)
	  : matcher{ database<inbound>{ inbound_file }, responses<outbound>{ outbound_file } } {}

    // Construct from matching inputs
    explicit matcher(const inputs &file)
      : matcher{ database<inbound>{ file.inbound }, responses<outbound>{ file.outbound } } {}

    // Construct from events
    explicit matcher(const database<inbound> &inbounds, const responses<outbound> &outbounds)
      : inbounds{ inbounds }, outbounds{ outbounds } {
		for (const auto &response : outbounds.valids) {
			const auto trigger = inbounds.events.find(response.id());
			if (trigger != inbounds.events.end()) {
				matches.push_back(event::match<inbound, outbound>(trigger->second, response));
			} else {
				misses.push_back(response);
			}
		}
    }

};

// Stream operator
template <class inbound, class outbound>
std::ostream &operator<<(std::ostream &out, const matcher<inbound, outbound> &matcher) {
	return out << "  Matched: " << matcher.matches.size() << std::endl
		       << "  Unmatched: " << matcher.misses.size() << std::endl;
}

} }

#endif
