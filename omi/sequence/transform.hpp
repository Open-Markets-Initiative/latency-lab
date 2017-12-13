#ifndef OMI_SEQUENCE_TRANSFORM_HPP_
#define OMI_SEQUENCE_TRANSFORM_HPP_

#include <vector>
#include <algorithm>
#include <type_traits>

// Sequence container transform

namespace omi { 
namespace sequence {


// https://stackoverflow.com/questions/23871757/the-stdtransform-like-function-that-returns-transformed-container

// Transform vector acoording to operation (move this)
template<typename type, typename function>
auto transform(const std::vector<type>& inputs, function operation) {
    std::vector<std::result_of_t<function(type)>> result(inputs.size()); // can we do this with generic container
    std::transform(inputs.begin(), inputs.end(), result.begin(), operation);
    return result;
} // make one that decides default constructability at compiletime

} }

#endif