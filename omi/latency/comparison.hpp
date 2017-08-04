#ifndef OMI_LATENCY_COMPARISON_HPP_
#define OMI_LATENCY_COMPARISON_HPP_

#include <omi/event/matcher.hpp>
#include <omi/latency/comparison/options.hpp>
#include <omi/latency/comparison/components.hpp>
#include <boost/filesystem.hpp>

// Latency comparison program template

namespace omi {
namespace latency {
namespace comparison {

const std::string INBOUND_EVENT_SUFFIX = "inbound";
const std::string OUTBOUND_EVENT_SUFFIX = "outbound";

std::string get_testname(const std::string &path) {
    boost::filesystem::path p = path;
    auto f = p.filename().string();
    auto i = f.find(INBOUND_EVENT_SUFFIX);
    return f.substr(0, i-1);
}

// returns what outbound file should be based on inbound file and outbound dir
boost::filesystem::path get_outbound_file(const boost::filesystem::path &inbound_file, const boost::filesystem::path &out_dir) {

    boost::filesystem::path outbound_file = out_dir;
    std::string in = inbound_file.filename().string();

    auto i = in.find(INBOUND_EVENT_SUFFIX);

    if (i != std::string::npos) {
        outbound_file += "/" + in.substr(0, i) + OUTBOUND_EVENT_SUFFIX;
    }

    return outbound_file;
}

std::vector<omi::event::inputs*> parse_dirs(const boost::filesystem::path &in, const boost::filesystem::path &out) {

    if (not boost::filesystem::exists(in) or not boost::filesystem::is_directory(in)) {
        throw std::invalid_argument("Invalid inbound directory: " + in.string());
    }

    if (not boost::filesystem::exists(out) or not boost::filesystem::is_directory(out)) {
        throw std::invalid_argument("Invalid outbound directory: " + out.string());
    }

    std::vector<omi::event::inputs*> input_vector;

    for (boost::filesystem::directory_entry& x : boost::filesystem::directory_iterator(in)) {

        bool isInboundFile = x.path().filename().string().find(INBOUND_EVENT_SUFFIX) != std::string::npos;

        // only create an input if both inbound and outbound exist
        if (isInboundFile) {
            auto inboundFile = x.path().filename().string();
            auto outboundFile = get_outbound_file(inboundFile, out);

            auto outboundExists = boost::filesystem::exists(outboundFile);

            if (outboundExists) {
                omi::event::inputs* input_item = new omi::event::inputs();
                input_item->inbound = x.path().string();
                input_item->outbound = outboundFile.string();

                input_vector.push_back(input_item);
            }
        }
    }

    return input_vector;
}

// Latency comparison html report program template
template <class inbound, class outbound>
void of(int argc, char *argv[]) {
	// Parse program options for settings
	auto options = comparison::options::parse(argc, argv);
	if (options.verbose) { std::cout << "Generate Latency Comparison Report" << std::endl; }

	// Stores test name key, delta value
	std::map<std::string, std::vector<double>> delta_map;

    boost::filesystem::path test_in = options.inbound_directory;
    boost::filesystem::path test_out = options.outbound_directory;
    auto input_vector = parse_dirs(test_in, test_out);
    std::cout << "input has " << input_vector.size() << " pairs" << std::endl;

    for (std::vector<omi::event::inputs*>::iterator it = input_vector.begin() ; it != input_vector.end(); ++it) {
        auto test_name = get_testname((*it)->inbound);
        const auto matched = event::matcher<inbound, outbound> {(*it)->inbound, (*it)->outbound};
        delta_map.insert(std::make_pair(test_name, matched.matched.deltas()));
    }

    comparison::components report;
    report.layout = options.report;
    report.delta_map = delta_map;

	// Generate report
	if (options.verbose) { std::cout << "Generating Report" << std::endl; }
	report.write(options.path);
}


} } }

#endif