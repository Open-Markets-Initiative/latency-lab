#ifndef OMI_WIRESHARK_MATCHER_HPP_
#define OMI_WIRESHARK_MATCHER_HPP_

#include <omi/wireshark/database.hpp>
#include <omi/wireshark/events.hpp>
#include <omi/wireshark/matching.hpp>
#include <omi/wireshark/options.hpp>

    // Match wireshark events by id

namespace omi { 
namespace wireshark {

template <class inbound, class outbound>
struct matcher {

  //// Member Variables ///////////

    const database<inbound> &inbounds;     // Inbound events database
    const responses<outbound> &outbounds;  // Outbound response events
	matches<inbound, outbound> matches;    // Matches
	std::vector<outbound> misses;          // Outbound repsonses without matching inbound event

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
			if (inbounds.has(response.id())) {
				auto &trigger = inbounds.get(response.id());
				auto matched = match<inbound, outbound>(trigger, response);
				matches.push_back(matched);
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
