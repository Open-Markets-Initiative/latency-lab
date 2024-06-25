set (REPORT_BINARY report)
add_executable(${REPORT_BINARY} main.cpp)
target_link_libraries(${REPORT_BINARY} PRIVATE ${Boost_INCLUDE_DIR})
target_link_libraries(${REPORT_BINARY} PRIVATE stdc++fs)