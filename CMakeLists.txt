cmake_minimum_required(VERSION 3.5)
project(omilatencylab)

# Set compiler flags
set(CMAKE_CXX_STANDARD 14)

# Set directories
set(OMI_DIR ${CMAKE_CURRENT_SOURCE_DIR}/omi)
set(EXAMPLE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/example)
set(TESTS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/tests)

if (WIN64)
    # Set boost location
    set(BOOST_ROOT "C:\\boost_1_63_0\\boost")
    set(BOOST_INCLUDE_DIR "C:\\boost_1_63_0")
    set(BOOST_LIBRARY_DIR "C:\\boost_1_63_0\\stage\\lib")

    # Find boost
    find_package(Boost COMPONENTS program_options REQUIRED)
else()
    set(BOOST_ROOT /home/parallels/Downloads/boost_1_63_0)
    find_package(Boost)

    set(Boost_INCLUDE_DIR ${BOOST_ROOT})
    set(Boost_LIBRARY_DIR ${BOOST_ROOT}/stage/lib)
endif()

# Include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${Boost_INCLUDE_DIR})
include_directories(${Boost_LIBRARY_DIR})

# Build example projects
add_executable(latency_comparison example/comparison/main.cpp)
target_link_libraries(latency_comparison
        ${Boost_LIBRARY_DIR}/libboost_filesystem.so
        ${Boost_LIBRARY_DIR}/libboost_system.so
        ${Boost_LIBRARY_DIR}/libboost_program_options.so)
