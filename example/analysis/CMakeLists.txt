set(ANALYSIS_BINARY analysis)
add_executable(${ANALYSIS_BINARY} main.cpp)
target_link_libraries(${ANALYSIS_BINARY} boost_program_options boost_filesystem boost_system)