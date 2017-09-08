add_executable(comparison main.cpp)
target_link_libraries(comparison
        ${Boost_LIBRARY_DIR}/libboost_filesystem.so
        ${Boost_LIBRARY_DIR}/libboost_system.so
        ${Boost_LIBRARY_DIR}/libboost_program_options.so)