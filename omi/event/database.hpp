#ifndef OMI_EVENT_DATABASE_HPP_
#define OMI_EVENT_DATABASE_HPP_

#include <omi/source/read.hpp>

#include <vector>
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

    // Static constructor for record by line file
    static database<record> read(const std::string &file) {
        return source::read<database<record>, record>(file);
    }

  //// Implementation /////////////

    void process(const record &event) {
        if (event.valid()) {
            auto pair = events.find(event.id());
            if (pair == events.end()) {
                // Add key to inbound events database
                events.insert({ event.id(), event });
            } else if (pair->second.time() > event.time()) {
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
std::ostream &operator<<(std::ostream &out, const database<record> &database) {
    return out << "  Processed: " << database.records() << std::endl
               << "  Valid: " << database.events.size() << std::endl
               << "  Duplicate: " << database.duplicates.size() << std::endl
               << "  Invalid: " << database.invalids.size() << std::endl;
}

} }

#endif
