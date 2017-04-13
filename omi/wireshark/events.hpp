#ifndef OMI_WIRESHARK_OUTBOUND_EVENTS_HPP_
#define OMI_WIRESHARK_OUTBOUND_EVENTS_HPP_

#include <omi/wireshark/event.hpp>

#include <string>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <iso646.h>

// Processed event records

namespace omi { 
namespace wireshark {

template <class record> // template on event also
struct table {

  //// Member Variables ///////////

    std::vector<event> valids;           // Valid processed events
    std::vector<record> invalids;        // Invalid records

  //// Construction ///////////////

    // Default constructor
    table() {}

    // File parsing constructor
    explicit table(const std::string &file) {
        // Verify file
        std::ifstream stream(file.c_str());
        if (not stream.good()) {
            throw std::invalid_argument("Invalid outbound events file: " + file);
        }

        // Parse and process records
        std::string line;
        uint32_t number = 0;
        while (std::getline(stream, line)) { // try boost memorymapped?
            process(record(line, ++number));
        }
    }

    // Process record entry
    void process(const record &entry) {
        if (entry.valid()) {
            valids.push_back(entry.event());
        } else {
            invalids.push_back(entry);
        }
    }

    // Return total records count
    size_t records() const {
        return valids.size() + invalids.size();
    }
};

// Stream operator
template <class record>
inline std::ostream &operator<<(std::ostream &out, const table<record> &events) {
    return out << "  Processed Records: " << events.records() << std::endl
               << "  Valid Records: " << events.valids.size() << std::endl
               << "  Invalid Records: " << events.invalids.size() << std::endl;
}

} }

#endif
