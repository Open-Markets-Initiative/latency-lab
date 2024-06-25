set(RACE_BINARY race)
add_executable(${RACE_BINARY} main.cpp)
target_link_libraries(${RACE_BINARY} Boost::program_options Boost::filesystem Boost::system)
target_link_libraries(${RACE_BINARY} stdc++fs)
