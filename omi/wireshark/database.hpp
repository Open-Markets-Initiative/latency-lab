#ifndef OMI_WIRESHARK_DATABASE_HPP_
#define OMI_WIRESHARK_DATABASE_HPP_

#include <omi/wireshark/event.hpp>

#include <fstream>
#include <string>
#include <unordered_map>

// Events Database

namespace omi { 
namespace wireshark {

template <class record> // template on event
struct database {

  //// Member Variables ///////////

    std::unordered_map<event::id, event> events;     // Events by id
    std::vector<event> duplicates;                   // Duplicate events
    std::vector<record> invalids;                    // Invalid records

  //// Construction ///////////////

    // Default constructor
    database() {}

    // Standard constructor
    explicit database(const std::string &file) {
        // Verify file
        std::ifstream stream(file.c_str());
        if (stream.bad()) {
            throw std::invalid_argument("Invalid file: " + file);
        }

        // Parse and process records
        std::string entry;
        uint32_t number = 0;
        while (std::getline(stream, entry)) {
            process(record(entry, ++number));
        }
    }

  //// Implementation /////////////

    void process(const record &entry) {
        if (entry.valid()) {
            const auto &event = entry.event();

            auto pair = events.find(event.identifier);
            if (pair == events.end()) {
                // Add key to inbound events database
                events.insert({ event.identifier, event });           
            } else if (pair->second.frame.timestamp > event.frame.timestamp) {
                // Duplicate events can be captured out of order
                duplicates.push_back(pair->second);
                pair->second = event;
            } else {
                // Add as duplicate
                duplicates.push_back(event);
            }
        }

        return invalids.push_back(entry);
    }

  /////////////////////////////////

    // Is id a valid event?
    bool has(event::id id) const {
         return events.count(id) == 1;
    }

    // Find market recrod by id
    event get(event::id id) const {
        return events.at(id);
    }

    // Return total records count
    size_t records() const {
        return events.size() + duplicates.size() + invalids.size();
    }

};


// Stream operator
template <class record>
inline std::ostream &operator<<(std::ostream &out, const database<record> &database) {
    return out << "  Processed Records: " << database.records() << std::endl
               << "  Event Ids: " << database.events.size() << std::endl
               << "  Duplicate Events: " << database.duplicates.size() << std::endl
               << "  Invalid Records: " << database.invalids.size() << std::endl ;
}

} }

#endif
