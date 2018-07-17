cmake_minimum_required(VERSION 3.11)

project(omilatencylab)
enable_testing()

# Set compiler flags
set(CMAKE_CXX_STANDARD 17)

# Set directories
set(OMI_DIR ${CMAKE_CURRENT_SOURCE_DIR}/omi)
set(EXAMPLE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/example)
set(TESTS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/tests)

if (WIN64)
    # Set boost location
    set(BOOST_ROOT "C:\\boost_1_64_0")
    set(BOOST_INCLUDE_DIR "C:\\boost_1_64_0")
    set(BOOST_LIBRARY_DIR "C:\\boost_1_64_0\\stage\\lib")
else()
    # Find boost
  #  set(BOOST_ROOT /home/parallels/Downloads/boost_1_64_0)
  #  set(Boost_INCLUDE_DIR ${BOOST_ROOT})
  #  set(Boost_LIBRARY_DIR ${BOOST_ROOT}/lib)
endif()

find_package(Boost REQUIRED COMPONENTS program_options filesystem system)

# Include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${Boost_INCLUDE_DIR})
include_directories(${Boost_LIBRARY_DIR})

# Build example projects
add_subdirectory(example/analysis)
add_subdirectory(example/comparison)
add_subdirectory(example/email)
add_subdirectory(example/matching)
add_subdirectory(example/race)
add_subdirectory(example/report)

# Tests
add_subdirectory(tests)
