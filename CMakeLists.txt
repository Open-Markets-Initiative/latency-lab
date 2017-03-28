cmake_minimum_required(VERSION 3.5)
project(omilatencylab)

# Set compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Set directories
set(OMI_DIR ${CMAKE_CURRENT_SOURCE_DIR}/omi)
set(EXAMPLE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/example)
set(TESTS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/tests)

# Set boost location
set(BOOST_ROOT "C:\\boost_1_63_0\\boost")
set(BOOST_INCLUDEDIR "C:\\boost_1_63_0")
set(BOOST_LIBRARYDIR "C:\\boost_1_63_0\\stage\\lib")

# Find boost
find_package(Boost COMPONENTS program_options REQUIRED)

# Include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${Boost_INCLUDE_DIR})

# Build example projects
add_executable(latency_report example/program/report/main.cpp)
target_link_libraries(latency_report ${Boost_LIBRARIES})
