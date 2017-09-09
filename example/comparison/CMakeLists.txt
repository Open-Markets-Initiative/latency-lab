set(COMPARISON_BINARY comparison)
add_executable(${COMPARISON_BINARY} main.cpp)
target_link_libraries(${COMPARISON_BINARY} boost_program_options boost_filesystem boost_system)
