#ifndef OMI_STYLE_CSS_HPP_
#define OMI_STYLE_CSS_HPP_

#include <omi/styles/standard.hpp>
#include <omi/source/whitespace.hpp>
#include <omi/html/declarations.hpp>

// Optional link to external style or inline default css declarations

namespace omi {
namespace style {

struct options { // need new name
	omi::whitespace whitespace;
	std::string link;

    explicit options(const std::string &file = "", indent whitespace = indent::none)
		: whitespace{ whitespace }, link{ file } {}
};

// Stream operator
inline std::ostream &operator<<(std::ostream &out, const options &options) {
	if (options.link.empty()) {
		return out << style::standard{};
	}

	return out << html::link{ "stylesheet", "text/css", options.link };
}

} }

#endif