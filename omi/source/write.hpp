#ifndef OMI_SOURCE_WRITE_HPP_
#define OMI_SOURCE_WRITE_HPP_

#include <fstream>

// Write any output to file

namespace omi {
namespace source {

template<typename output>
void write(const output &out, const std::string &path) {
    // Verify output file
    std::ofstream stream(path);
    if (not stream.good()) {
        throw std::invalid_argument("Invalid file: " + path);
    }

    stream << out;
}

} }

#endif