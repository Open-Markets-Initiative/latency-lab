set (COMPARISON_BINARY comparison)
add_executable(${COMPARISON_BINARY} main.cpp)
target_link_libraries(${COMPARISON_BINARY} PRIVATE ${Boost_INCLUDE_DIR})
target_link_libraries(${COMPARISON_BINARY} PRIVATE stdc++fs)
