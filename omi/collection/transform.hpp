#ifndef OMI_COLLECTION_TRANSFORM_HPP_
#define OMI_COLLECTION_TRANSFORM_HPP_

#include <vector>
#include <algorithm>
#include <type_traits>

// Container transform

namespace omi { 
namespace collection {

// https://stackoverflow.com/questions/23871757/the-stdtransform-like-function-that-returns-transformed-container
// make one that decides default constructability at compiletime

// Transform vector acoording to operation
template < typename container, typename function, typename type = typename container::value_type>
auto transform(const container &elements, function && functor) {
    std::vector<std::result_of_t<function(type)>> result(elements.size());
    std::transform(std::begin(elements), std::end(elements), std::begin(result), functor);
    return result;
} 

} }

#endif