set(MATCHING_BINARY matching)
add_executable(${MATCHING_BINARY} main.cpp)
target_link_libraries(${MATCHING_BINARY} Boost::program_options Boost::filesystem Boost::system)
target_link_libraries(${MATCHING_BINARY} stdc++fs)
