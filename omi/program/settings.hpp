#ifndef OMI_PROGRAM_SETTINGS_HPP_
#define OMI_PROGRAM_SETTINGS_HPP_

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>

#include <stdexcept>
#include <iso646.h>

    // Omi program settings

namespace omi {
namespace program {

struct Settings {

  //// Member variables ///////////

    boost::property_tree::ptree properties;

  //// Construction ///////////////

    // Default constructor
    Settings() {}

    // Load settings from boost property tree
    explicit Settings(const boost::property_tree::ptree &tree) 
      : properties{ tree } {}

    // Load settings from file
    explicit Settings(const std::string &file) {
        boost::property_tree::ini_parser::read_ini(file, properties);
    }

  //// Methods ////////////////////

    // Conditional returns value if it exists,  returns 
    template<typename T>
    T conditional(const std::string field, const T &value) const {
        return properties.get<T>(field, value);
    }

    // Convenience method for setting optional value only if setting exists
    template<typename T>
    boost::optional<T> optional(const std::string field) const {
        return properties.get_optional<T>(field);
    }

    // Required settings value
    template<typename T>
    T required(const std::string field) const {
        // Verify required field exists
        if (not exists(field)) {
            throw std::invalid_argument("Missing setting => " + field);
        }

        return properties.get<T>(field);
    }

    // Retrieve ini section
    Settings section(const std::string name) const {
        return Settings{ properties.get_child(name) };
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
    bool exists(const std::string field) const noexcept {
        return properties.count(field) > 0;
    }

    // Total number of settings
    size_t count() const noexcept {
        return properties.size();
    }
};

} }

#endif
