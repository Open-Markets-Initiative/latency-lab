set (ANALYSIS_BINARY analysis)
add_executable(${ANALYSIS_BINARY} main.cpp)
target_link_libraries(${ANALYSIS_BINARY} PRIVATE ${Boost_INCLUDE_DIR})
target_link_libraries(${ANALYSIS_BINARY}  PRIVATE stdc++fs)