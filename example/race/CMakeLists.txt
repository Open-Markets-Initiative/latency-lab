set (RACE_BINARY race)
add_executable(${RACE_BINARY} main.cpp)
target_link_libraries(${RACE_BINARY} PRIVATE ${Boost_INCLUDE_DIR})
target_link_libraries(${RACE_BINARY} PRIVATE stdc++fs)
