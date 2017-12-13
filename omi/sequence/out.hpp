#ifndef OMI_SEQUENCE_OUT_HPP_
#define OMI_SEQUENCE_OUT_HPP_

#include <ostream>

// Container out

namespace omi { 
namespace sequence {

// Stream out all elements in a container 
template<typename container>
auto out(std::ostream &out, const container &elements) {
    for (const auto &element : elements) {
        out << element << std::endl;
    }

    return out;
}

} }

#endif