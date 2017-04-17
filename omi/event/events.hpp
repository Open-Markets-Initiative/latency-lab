#ifndef OMI_EVENT_EVENTS_HPP_
#define OMI_EVENT_EVENTS_HPP_

#include <omi/source/read.hpp>

#include <vector>

// Processed event records

namespace omi { 
namespace event {

template <class record>
struct events {

  //// Member Variables ///////////

    std::vector<record> valids;          // Valid processed events
    std::vector<record> invalids;        // Invalid records

  //// Construction ///////////////

    // Default constructor
    events() {}

    // Static constructor for record by line file
    static events<record> read(const std::string &file) {
        return source::read<events<record>, record>(file); // TODO: verify this does not create a copy
    }

  //// Implementation /////////////

    // Process record
    void process(const record &event) {
        if (event.valid()) {
            valids.push_back(event);
        } else {
            invalids.push_back(event);
        }
    }

    // Return total records count
    size_t records() const {
        return valids.size() + invalids.size();
    }
};

// convenience template for responses
template<class outbound> using responses = events<outbound>;

// Stream operator
template <class record>
std::ostream &operator<<(std::ostream &out, const responses<record> &events) {
    return out << "  Processed: " << events.records() << std::endl
               << "  Valid: " << events.valids.size() << std::endl
               << "  Invalid: " << events.invalids.size() << std::endl;
}

} }

#endif
