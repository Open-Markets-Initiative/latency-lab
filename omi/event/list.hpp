#ifndef OMI_EVENT_EVENTS_HPP_
#define OMI_EVENT_EVENTS_HPP_

#include <vector>

#include <omi/source/read.hpp>

// Processed event records

namespace omi::event {

template <typename record>
struct list {

  //// Member Variables ///////////

    std::vector<record> valids;    // Valid processed events
    std::vector<record> invalids;  // Invalid records

  //// Construction ///////////////

    // Default constructor
    list() {}

    // Static constructor for record by line file
    static auto read(const std::string &file) {
        return source::read<list, record>(file); // TODO: verify this does not create a copy
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

// Stream operator
template <typename record>
std::ostream &operator<<(std::ostream &out, const list<record> &events) {
    return out << "  Processed: " << events.records() << std::endl
               << "  Valid: " << events.valids.size() << std::endl
               << "  Invalid: " << events.invalids.size() << std::endl;
}

}

#endif