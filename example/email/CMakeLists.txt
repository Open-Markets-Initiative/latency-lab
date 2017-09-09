set(EMAIL_BINARY email)
add_executable(${EMAIL_BINARY} main.cpp)
target_link_libraries(${EMAIL_BINARY} boost_program_options boost_filesystem boost_system)
