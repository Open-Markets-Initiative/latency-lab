#ifndef OMI_EVENT_DICTIONARY_HPP_
#define OMI_EVENT_DICTIONARY_HPP_

#include <vector>
#include <unordered_map>

#include <omi/source/read.hpp>

// Events database

namespace omi::event {

template <typename record>
struct dictionary {

  //// Member Variables ///////////

    // Record database (events by id: earliest time)
    std::unordered_map<decltype(std::declval<record>().id()), record> events;

    std::vector<record> duplicates;      // Duplicate records
    std::vector<record> invalids;        // Invalid records

  //// Construction ///////////////

    // Default constructor
    dictionary() {}

    // Static constructor for reading records from line by line file
    static auto read(const std::string &file) {
        return source::read<dictionary, record>(file);
    }

  //// Implementation /////////////

    void process(const record &event) {
        if (event.valid()) {
            const auto &key = event.id();
            auto pair = events.find(key);
            if (pair == events.end()) {
                // Add key to inbound events database
                events.insert({ key, event });
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
template <typename record>
std::ostream &operator<<(std::ostream &out, const dictionary<record> &database) {
    return out << "  Processed: " << database.records() << std::endl
               << "  Valid: " << database.events.size() << std::endl
               << "  Duplicate: " << database.duplicates.size() << std::endl
               << "  Invalid: " << database.invalids.size() << std::endl;
}

}

#endif