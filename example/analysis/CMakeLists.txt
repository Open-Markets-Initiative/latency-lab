set(ANALYSIS_BINARY analysis)
add_executable(${ANALYSIS_BINARY} main.cpp)
target_link_libraries(${ANALYSIS_BINARY} Boost::program_options Boost::filesystem Boost::system)
target_link_libraries(${ANALYSIS_BINARY} stdc++fs)