#ifndef OMI_DIRECTORY_PARSING_HPP_
#define OMI_DIRECTORY_PARSING_HPP_

#include <filesystem>

#include <omi/match/paths.hpp>

// Directory methods (Under construction)

namespace omi::directory {

const std::string INBOUND_EVENT_SUFFIX = "inbound";
const std::string OUTBOUND_EVENT_SUFFIX = "outbound";

// need to move this
inline std::string name(const std::string &path) {
    std::filesystem::path p = path;
    auto name = p.filename().string();
    auto index = name.find(INBOUND_EVENT_SUFFIX);

    return name.substr(0, index-1);
}

// Returns what outbound file should be based on inbound file and outbound dir
inline auto find(const std::filesystem::path &file, const std::filesystem::path &directory) {
    auto result = directory;
    auto name = file.filename().string();

    auto index = name.find(INBOUND_EVENT_SUFFIX);
    if (index != std::string::npos) {
        result += "/" + name.substr(0, index) + OUTBOUND_EVENT_SUFFIX;
    }

    return result;
}

// Return matching inputs from directories
inline auto parse(const std::filesystem::path &inbounds, const std::filesystem::path &outbounds) {
    if (not is_directory(inbounds)) {
        throw std::invalid_argument("Invalid inbound directory: " + inbounds.string());
    }

    if (not is_directory(outbounds)) {
        throw std::invalid_argument("Invalid outbound directory: " + outbounds.string());
    }

    std::vector<omi::match::paths> result;
    for (auto& entry : std::filesystem::directory_iterator(inbounds)) {
        if (not exists(entry)) { continue; }

        const auto outbound = find(entry.path().filename().string(), outbounds);
        if (exists(outbound)) {
          result.push_back({ entry.path(), outbound });
        }
    }

    return result;
}

// Return matching inputs from directories 
inline auto parse(const std::string &inbound, const std::string &outbound) {
    return parse(std::filesystem::path{inbound}, std::filesystem::path{outbound});
}

}

#endif