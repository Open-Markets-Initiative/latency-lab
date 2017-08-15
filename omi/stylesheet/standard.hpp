#ifndef OMI_STYLESHEET_STANDARD_HPP_
#define OMI_STYLESHEET_STANDARD_HPP_

#include <omi/css/rules.hpp>

// Common omi css style 1

namespace omi {
namespace stylesheet {

struct standard {
    std::string whitespace;

    explicit standard(const std::string &whitespace = "")
     : whitespace {whitespace} {}
};

//TODO: break this up
inline std::ostream &operator<<(std::ostream &out, const standard &one) {
    return out << css::rule{"body",
                    css::declaration{"font-family", "Verdana,sans-serif"},
                    css::declaration{"font-size", "0.9em"}}
               << std::endl
               << css::rule{"header",
                    css::declaration{"padding", "10px"},
                    css::declaration{"color", "white"},
                    css::declaration{"background-color", "#3366cc"}}
               << std::endl
               << css::rule{"footer",
                    css::declaration{"padding", "5px"},
                    css::declaration{"color", "white"},
                    css::declaration{"background-color", "#669999"}}
               << std::endl
               << css::rule{"section",
                    css::declaration{"margin", "5px"},
                    css::declaration{"padding", "10px"},
                    css::declaration{"background-color", "lightgrey"}}
               << std::endl
               << css::rule{"article",
                    css::declaration{"margin", "5px"},
                    css::declaration{"padding", "10px"},
                    css::declaration{"background-color", "white"}}
               << std::endl
               << css::rule{"nav ul",
                    css::declaration{"padding", "0"}}
               << std::endl
               << css::rule{"nav ul",
                    css::declaration{"display", "inline"},
                    css::declaration{"margin", "5px" }}
               << std::endl
               << css::rule{"table.gridtable",
                    css::declaration{"font-family", "verdana,arial,sans-serif"},
                    css::declaration{"font-size", "11px"},
                    css::declaration{"color", "#333333"},
                    css::declaration{"border-width", "1px" },
                    css::declaration{"border-color", "#666666" },
                    css::declaration{"border-collapse", "collapse" } }
               << std::endl
               << css::rule{"table.gridtable th",
                    css::declaration{"padding", "8px"},
                    css::declaration{"border-width", "1px" },
                    css::declaration{"border-style", "solid" },
                    css::declaration{"border-color", "#666666" },
                    css::declaration{"background-color", "#dedede"}}
               << std::endl
               << css::rule{"table.gridtable td",
                    css::declaration{"padding", "8px"},
                    css::declaration{"border-width", "1px" },
                    css::declaration{"border-style", "solid" },
                    css::declaration{"border-color", "#666666" },
                    css::declaration{"background-color", "#ffffff"}};
}

} }

#endif