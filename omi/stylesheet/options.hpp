#ifndef OMI_STYLEHEET_OPTIONS_HPP_
#define OMI_STYLEHEET_OPTIONS_HPP_

#include <omi/stylesheet/standard.hpp>
#include <omi/source/whitespace.hpp>
#include <omi/html/declarations.hpp>

// Optional link to external style or inline default css declarations

namespace omi {
namespace stylesheet {

struct options { // need new name
	omi::whitespace whitespace;
	std::string link;

    explicit options(const std::string &file = "", indent whitespace = indent::none)
		: whitespace{ whitespace }, link{ file } {}
};

// Stream operator
inline std::ostream &operator<<(std::ostream &out, const options &options) {
	if (options.link.empty()) {
		return out << stylesheet::standard{};
	}

	return out << html::link{ "stylesheet", "text/css", options.link };
}

} }

#endif