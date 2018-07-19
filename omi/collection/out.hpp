#ifndef OMI_COLLECTION_OUT_HPP_
#define OMI_COLLECTION_OUT_HPP_

#include <ostream>

// Container out

namespace omi::collection {

// Stream out all elements in a container 
template<typename container>
auto stream(std::ostream &out, const container &elements) {
    for (const auto &element : elements) {
        out << element << std::endl;
    }

    return out;
}

}

#endif