set (EMAIL_BINARY email)
add_executable(${EMAIL_BINARY} main.cpp)
target_link_libraries(${EMAIL_BINARY} PRIVATE ${Boost_INCLUDE_DIR})
target_link_libraries(${EMAIL_BINARY} PRIVATE stdc++fs)