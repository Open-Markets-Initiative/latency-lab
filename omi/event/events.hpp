#ifndef OMI_EVENT_EVENTS_HPP_
#define OMI_EVENT_EVENTS_HPP_

#include <string>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <iso646.h>

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

    // File parsing constructor
    explicit events(const std::string &file) {
        // Verify file
        std::ifstream stream(file.c_str());
        if (not stream.good()) {
            throw std::invalid_argument("Invalid responses file: " + file);
        }

        // Parse and process records
        std::string line;
        uint32_t number = 0;
        while (std::getline(stream, line)) { // template file reading
            process(record(line, ++number));
        }
    }

    // Process record entry
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
    return out << "  Processed Records: " << events.records() << std::endl
               << "  Valid Records: " << events.valids.size() << std::endl
               << "  Invalid Records: " << events.invalids.size() << std::endl;
}

} }

#endif
