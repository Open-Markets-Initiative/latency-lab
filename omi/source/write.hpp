#ifndef OMI_SOURCE_WRITE_HPP_
#define OMI_SOURCE_WRITE_HPP_

#include <fstream>

// write any output object to file

namespace omi {
namespace source {

template<typename output>
inline void write(const output &report, const std::string &path) {
    // Verify output file
    std::ofstream stream(path);
    if (stream.bad()) {
        throw std::invalid_argument("Report output file invalid: " + path);
    }

    // TODO: Print some empty html when there are no values...how to do this?

    stream << report;
}

} }

#endif
