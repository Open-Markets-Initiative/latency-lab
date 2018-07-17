#ifndef OMI_COLLECTION_SIZE_HPP_
#define OMI_COLLECTION_SIZE_HPP_

// Sequence size functions

namespace omi {
namespace collection {

// Todo: add static_asset that value type can be calculated
// Todo: full unit tests

// Is container empty?
template <typename container>
bool empty(container &values) {
    return values.begin() == values.end();
}

// Calculate count
template <typename container>
size_t count(container &values) {
    return values.size();
}


} }

#endif