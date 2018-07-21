#ifndef OMI_MATCH_PATHS_HPP_
#define OMI_MATCH_PATHS_HPP_

#include <ostream>
#include <filesystem>

#include <omi/match/inputs.hpp>

// Match paths

namespace omi::match {

struct paths {
    std::filesystem::path inbound;    // Inbound events file
    std::filesystem::path outbound;   // Outbound events file
};

inline paths parse(const inputs &input) {
    return paths {std::filesystem::path(input.inbound), std::filesystem::path(input.outbound)};
}

// Stream operator
inline std::ostream &operator<<(std::ostream &out, const paths &path) {
    return out << "  Inbound: " << path.inbound << std::endl
               << "  Outbound: " << path.outbound << std::endl;
}

}

#endif