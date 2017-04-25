#ifndef OMI_EVENT_ASSERTS_HPP_
#define OMI_EVENT_ASSERTS_HPP_

#include <omi/event/info.hpp>

#include <type_traits>

// Compiletime event asserts

namespace omi {
namespace event {

// Are records matchable?
template <class inbound, class outbound>
constexpr bool is_matchable = std::is_same<decltype(std::declval<inbound>().id()), decltype(std::declval<outbound>().id())>::value;

} }

#endif