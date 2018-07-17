set(RACE_BINARY race)
add_executable(${RACE_BINARY} main.cpp)
target_link_libraries(${RACE_BINARY} ${Boost_LIBRARIES})
