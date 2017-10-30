#ifndef OMI_CONTAINER_DEFINITIONS_HPP_
#define OMI_CONTAINER_DEFINITIONS_HPP_

#include <omi/event/match.hpp>


#include <vector>
#include <algorithm>
#include <type_traits>

// Matches 

namespace omi { 

// Transform vector acoording to operation (move this)
template<typename type, typename function>
auto transform(const std::vector<type>& inputs, function operation) {
    std::vector<std::result_of_t<function(type)>> result(inputs.size());
    std::transform(inputs.begin(), inputs.end(), result.begin(), operation);
    return result;
} // make one that decides default constructability at compiletime

// Stream out all elements in a container 
template<typename container>
auto out(std::ostream &out, const container &elements) {
    for (const auto &element : elements) {
        out << element << std::endl;
    }

    return out;
}

}

#endif