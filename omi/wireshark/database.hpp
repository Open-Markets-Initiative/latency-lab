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
    std::string name;                                // Name (cosmetic)

  //// Construction ///////////////

    // Default constructor
    database() {}

    // Standard constructor
    explicit database(const std::string &file, const std::string  &name = "Inbound events") : name{ name } {
        // Verify file
        std::ifstream stream(file.c_str());
        if (stream.bad()) {
            throw std::invalid_argument(name + " file invalid: " + file);
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
            if (events.count(event.identifier) == 0) {
                events.insert({ event.identifier, event });           
            } else {
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
    return out << database.name << std::endl
               << "  Processed Records: " << database.records() << std::endl
               << "  Event Ids: " << database.events.size() << std::endl
               << "  Duplicate Events: " << database.duplicates.size() << std::endl
               << "  Invalid Records: " << database.invalids.size() << std::endl ;
}

} }

#endif
