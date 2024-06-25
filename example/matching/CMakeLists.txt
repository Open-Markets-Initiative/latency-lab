set(MATCHING_BINARY matching)
add_executable(${MATCHING_BINARY} main.cpp)
target_link_libraries(${MATCHING_BINARY} PRIVATE ${Boost_INCLUDE_DIR})
target_link_libraries(${MATCHING_BINARY} PRIVATE stdc++fs)
