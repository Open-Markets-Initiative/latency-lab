add_executable(comparison main.cpp)
target_link_libraries(comparison Boost::program_options Boost::filesystem Boost::system)
target_link_libraries(comparison stdc++fs)
