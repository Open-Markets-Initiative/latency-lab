#ifndef OMI_SOURCE_READ_HPP_
#define OMI_SOURCE_READ_HPP_

#include <fstream>
#include <string>

// Write any output to file

namespace omi {
namespace source {

template<class input, class record>
input read(const std::string &path) {
    // Verify file
    std::ifstream stream(path.c_str());
    if (stream.bad()) {
        throw std::invalid_argument("Invalid file: " + path);
    }

    input result;

    // Parse and process records
    std::string entry;
    uint32_t number = 0;
    while (std::getline(stream, entry)) {
        result.process(record(entry, ++number));
    }

    return result;
}

} }

#endif
