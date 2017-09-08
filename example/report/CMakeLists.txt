add_executable(report main.cpp)
target_link_libraries(report
        ${Boost_LIBRARY_DIR}/libboost_filesystem.so
        ${Boost_LIBRARY_DIR}/libboost_system.so
        ${Boost_LIBRARY_DIR}/libboost_program_options.so)