cmake_minimum_required(VERSION 3.5)
project(omilatencylab)

# Set compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Set Boost location NOTE: set this to your boost location
set(BOOST_ROOT "windows/packages/boost.1.63.0.0")

# Find required packages
find_package(Boost 1.63 COMPONENTS program_options REQUIRED)

# Include directories
include_directories(omi)
include_directories(${boost_SOURCE_DIR}/include $boost_SOURCE_DIR})

# Build example projects
add_executable(chart example/program/charter.cpp)
target_link_libraries(chart ${Boost_LIBRARIES})
