#ifndef OMI_EVENT_DATABASE_HPP_
#define OMI_EVENT_DATABASE_HPP_

#include <fstream>
#include <string>
#include <unordered_map>

// Events database

namespace omi { 
namespace event {

template <class record>
struct database {

  //// Member Variables ///////////

    std::unordered_map<typename record::identifier, record> events;    // Records by earliest time
    std::vector<record> duplicates;                                    // Duplicate records
    std::vector<record> invalids;                                      // Invalid records

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

    void process(const record &event) {
        if (event.valid()) {
            auto pair = events.find(event.id());
            if (pair == events.end()) {
                // Add key to inbound events database
                events.insert({ event.id(), event });
            } else if (pair->second.microseconds() > event.microseconds()) {
                // Duplicate events can be captured out of order
                duplicates.push_back(pair->second);
                pair->second = event;
            } else {
                // Add as duplicate
                duplicates.push_back(event);
            }
        }

        return invalids.push_back(event);
    }

  /////////////////////////////////

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
