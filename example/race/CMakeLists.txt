add_executable(race main.cpp)
target_link_libraries(race Boost::program_options Boost::filesystem Boost::system)
target_link_libraries(race stdc++fs)
