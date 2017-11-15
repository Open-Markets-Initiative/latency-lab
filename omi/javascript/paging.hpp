#ifndef OMI_JAVASCRIPT_PAGING_HPP_
#define OMI_JAVASCRIPT_PAGING_HPP_

#include <omi/source/whitespace.hpp>

// Javascript page functions

namespace omi {
namespace javascript {

struct paging {
    // script options
    omi::whitespace whitespace;

    // Constructor
    explicit paging(const indent whitespace = indent::none)
      : whitespace{ whitespace } {}
};



// Stream operator
inline std::ostream &operator<<(std::ostream &out, const paging &paging) {
    return out << paging.whitespace << "  function select(evt, testName) {" << std::endl
               << paging.whitespace << "    var i, tabcontent, tablinks;" << std::endl
               << paging.whitespace << "    tabcontent = document.getElementsByClassName(\"tabcontent\")" << std::endl
               << paging.whitespace << "    for (i = 0; i < tabcontent.length; i++) {" << std::endl
               << paging.whitespace << "      tabcontent[i].style.display = \"none\";" << std::endl
               << paging.whitespace << "    }" << std::endl
               << paging.whitespace << "    tablinks = document.getElementsByClassName(\"tablinks\");" << std::endl
               << paging.whitespace << "    for (i = 0; i < tablinks.length; i++) {" << std::endl
               << paging.whitespace << "      tablinks[i].className = tablinks[i].className.replace(\" active\", \"\");" << std::endl
               << paging.whitespace << "    }" << std::endl
               << paging.whitespace << "    document.getElementById(testName).style.display = \"block\";" << std::endl
               << paging.whitespace << "    evt.currentTarget.className += \" active\";" << std::endl
               << paging.whitespace << "  }" << std::endl;
}

} }

#endif