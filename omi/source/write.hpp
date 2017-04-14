#ifndef OMI_SOURCE_WRITE_HPP_
#define OMI_SOURCE_WRITE_HPP_

#include <fstream>

// Write any output to file

namespace omi {
namespace source {

template<typename output>
void write(const output &report, const std::string &path) {
    // Verify output file
    std::ofstream stream(path);
    if (stream.bad()) {
        throw std::invalid_argument("Invalid file: " + path);
    }

    // TODO: Print some empty html when there are no values...how to do this?

    stream << report;
}

} }

#endif
