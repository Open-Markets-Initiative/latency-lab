set(EMAIL_BINARY email)
add_executable(${EMAIL_BINARY} main.cpp)
target_link_libraries(${EMAIL_BINARY} Boost::program_options Boost::filesystem Boost::system)
target_link_libraries(${EMAIL_BINARY} stdc++fs)