cmake_minimum_required(VERSION 3.9)
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
    set(BOOST_ROOT /home/travis/build/Open-Markets-Initiative/latency-lab/boost_1_64_0)
    find_package(Boost REQUIRED COMPONENTS program_options filesystem system)
endif()

# Include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIR})

# Build example projects
ADD_SUBDIRECTORY(example/analysis)
ADD_SUBDIRECTORY(example/comparison)
ADD_SUBDIRECTORY(example/email)
ADD_SUBDIRECTORY(example/matching)
ADD_SUBDIRECTORY(example/report)

