#ifndef OMI_DIRECTORY_PARSING_HPP_
#define OMI_DIRECTORY_PARSING_HPP_

#include <boost/filesystem.hpp>

    // Directory methods (Under construction)

namespace omi::directory {

const std::string INBOUND_EVENT_SUFFIX = "inbound";
const std::string OUTBOUND_EVENT_SUFFIX = "outbound";

// need to move this
inline std::string name(const std::string &path) {
    boost::filesystem::path p = path;
    auto name = p.filename().string();
    auto index = name.find(INBOUND_EVENT_SUFFIX);

    return name.substr(0, index-1);
}

// Returns what outbound file should be based on inbound file and outbound dir
inline boost::filesystem::path find(const boost::filesystem::path &file, const boost::filesystem::path &directory) {
    auto result = directory;
    auto name = file.filename().string();

    auto index = name.find(INBOUND_EVENT_SUFFIX);
    if (index != std::string::npos) {
        result += "/" + name.substr(0, index) + OUTBOUND_EVENT_SUFFIX;
    }

    return result;
}

// Return matching inputs from directories
inline auto parse(const boost::filesystem::path &in, const boost::filesystem::path &out) {
    if (not boost::filesystem::is_directory(in)) {
        throw std::invalid_argument("Invalid inbound directory: " + in.string());
    }

    if (not boost::filesystem::is_directory(out)) {
        throw std::invalid_argument("Invalid outbound directory: " + out.string());
    }

    std::vector<omi::match::inputs> inputs;
    for (auto& entry : boost::filesystem::directory_iterator(in)) {
        if (exists(entry)) {
            auto inbound = entry.path().filename().string();
            auto outbound = find(inbound, out);

            if (boost::filesystem::exists(outbound)) {
                match::inputs item;
                  item.inbound = entry.path().string();
                  item.outbound = outbound.string();

                inputs.push_back(item);
            }
        }
    }

    return inputs;
}

// Does 
inline auto exists(boost::filesystem::directory_entry& entry, const std::string &file = INBOUND_EVENT_SUFFIX) {
    return entry.path().filename().string().find(file) != std::string::npos;
}

// Return matching inputs from directories 
inline auto parse(const std::string &inbound, const std::string &outbound) {
    return parse(boost::filesystem::path{inbound}, boost::filesystem::path{outbound});
}

}

#endif