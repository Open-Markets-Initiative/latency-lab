#ifndef OMI_SOURCE_READ_HPP_
#define OMI_SOURCE_READ_HPP_

#include <fstream>
#include <string>

// Read records line by line

namespace omi {
namespace source {

template<class input, class record>
auto read(const std::string &path) {
    // Verify file
    std::ifstream stream(path.c_str());
    if (not stream.good()) {
        throw std::invalid_argument("Invalid file: " + path);
    }

    input result;

    // Process records
    std::string line;
    auto number{ 0u };
    while (std::getline(stream, line)) {
        auto entry = record{line, ++number};
        result.process(entry);
    }

    return result;
}

} }

#endif