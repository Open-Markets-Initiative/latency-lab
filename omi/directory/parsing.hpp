#ifndef OMI_DIRECTORY_PARSING_HPP_
#define OMI_DIRECTORY_PARSING_HPP_

#include <boost/filesystem.hpp>

    // Directory methods (Under construction)

namespace omi { 
namespace directory {

const std::string INBOUND_EVENT_SUFFIX = "inbound";
const std::string OUTBOUND_EVENT_SUFFIX = "outbound";

// need to move this
inline std::string name(const std::string &path) {
    boost::filesystem::path p = path;
    auto f = p.filename().string();
    auto i = f.find(INBOUND_EVENT_SUFFIX);

    return f.substr(0, i-1);
}

// Returns what outbound file should be based on inbound file and outbound dir
inline boost::filesystem::path find(const boost::filesystem::path &inbound_file, const boost::filesystem::path &out_dir) {
    boost::filesystem::path outbound_file = out_dir;
    std::string in = inbound_file.filename().string();

    auto i = in.find(INBOUND_EVENT_SUFFIX);
    if (i != std::string::npos) {
        outbound_file += "/" + in.substr(0, i) + OUTBOUND_EVENT_SUFFIX;
    }

    return outbound_file;
}

// Return matching inputs from directories
inline auto parse(const boost::filesystem::path &in, const boost::filesystem::path &out) {
    if (not boost::filesystem::exists(in) or not boost::filesystem::is_directory(in)) {
        throw std::invalid_argument("Invalid inbound directory: " + in.string());
    }

    if (not boost::filesystem::exists(out) or not boost::filesystem::is_directory(out)) {
        throw std::invalid_argument("Invalid outbound directory: " + out.string());
    }

    std::vector<omi::match::inputs> input_vector;
    for (boost::filesystem::directory_entry& entry : boost::filesystem::directory_iterator(in)) {
        auto isInboundFile = entry.path().filename().string().find(INBOUND_EVENT_SUFFIX) != std::string::npos;

        // Create an input if both inbound and outbound exist
        if (isInboundFile) {
            auto inboundFile = entry.path().filename().string();
            auto outbound = find(inboundFile, out);

            if (boost::filesystem::exists(outbound)) {
                match::inputs item;
                  item.inbound = entry.path().string();
                  item.outbound = outbound.string();

                input_vector.push_back(item);
            }
        }
    }

    return input_vector;
}

// Return matching inputs from directories 
inline auto parse(const std::string &inbound, const std::string &outbound) {
    return parse(boost::filesystem::path{inbound}, boost::filesystem::path{outbound});
}

} }

#endif