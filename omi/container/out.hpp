#ifndef OMI_CONTAINER_OUT_HPP_
#define OMI_CONTAINER_OUT_HPP_

#include <ostream>

// Container out

namespace omi { 
namespace container {

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