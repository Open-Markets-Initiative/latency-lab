set(MATCHING_BINARY matching)
add_executable(${MATCHING_BINARY} main.cpp)
target_link_libraries(${MATCHING_BINARY} boost_program_options boost_filesystem boost_system)
