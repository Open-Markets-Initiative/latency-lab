set(REPORT_BINARY report)
add_executable(${REPORT_BINARY} main.cpp)
target_link_libraries(${REPORT_BINARY} boost_filesystem boost_system boost_program_options)
