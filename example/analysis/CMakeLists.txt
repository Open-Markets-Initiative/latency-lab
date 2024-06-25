add_executable(analysis main.cpp)
target_link_libraries(analysis Boost::program_options Boost::filesystem Boost::system)
target_link_libraries(analysis stdc++fs)