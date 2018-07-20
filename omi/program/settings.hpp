#ifndef OMI_PROGRAM_SETTINGS_HPP_
#define OMI_PROGRAM_SETTINGS_HPP_

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>

#include <stdexcept>
#include <optional>
#include <iso646.h>

    // Omi program settings

namespace omi::program {

struct settings {

  //// Member variables ///////////

    boost::property_tree::ptree properties;

  //// Construction ///////////////

    // Default constructor
    settings() = default;

    // Load settings from boost property tree
    explicit settings(const boost::property_tree::ptree &tree) 
      : properties{ tree } {}

    // Load settings from file
    explicit settings(const std::string &file) {
        boost::property_tree::ini_parser::read_ini(file, properties);
    }

  //// Methods ////////////////////

    // Conditional returns value if it exists
    template<typename T>
    T conditional(const std::string field, const T &value) const {
        return properties.get<T>(field, value);
    }

    // Convenience method for setting optional value
    template<typename T>
    std::optional<T> optional(const std::string field) const {
        return exists(field) ? properties.get<T>(field) : std::optional<T>();
    }

    // Required settings value
    template<typename T>
    T required(const std::string field) const {
        // Verify required field exists
        if (exists(field)) {
            return properties.get<T>(field);
        }

        throw std::invalid_argument("Missing setting => " + field);
    }

    // Retrieve ini section
    settings section(const std::string name) const {
        return settings{ properties.get_child(name) };
    }

  //////////////////////////

    // Add setting
    template<typename T>
    bool set(const std::string field, const T &value) {
        // What happens on strange types?  Need to check this
        properties.put(field, value); 
        return true;
    }

  //// Stats //////////////////////

    // Does setting exist?
    bool exists(const std::string& field) const noexcept {
        return properties.count(field) > 0;
    }

    // Total number of settings
    size_t count() const noexcept {
        return properties.size();
    }
};

}

#endif