add_executable(email main.cpp)
target_link_libraries(email Boost::program_options Boost::filesystem Boost::system)
target_link_libraries(email stdc++fs)