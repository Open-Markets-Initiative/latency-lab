set(REPORT_BINARY report)
add_executable(${REPORT_BINARY} main.cpp)
target_link_libraries(${REPORT_BINARY} Boost::program_options Boost::filesystem Boost::system)
target_link_libraries(${REPORT_BINARY} stdc++fs)