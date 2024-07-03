cmake_minimum_required(VERSION 3.18)

project(omilatencylab)
enable_testing()

# Set compiler flags
set(CMAKE_CXX_STANDARD 17)

# Set directories
set(OMI_DIR ${CMAKE_CURRENT_SOURCE_DIR}/omi)
set(EXAMPLE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/example)
set(TESTS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/tests)

# Find boost
find_package(Boost 1.67 REQUIRED COMPONENTS program_options filesystem system)

set (Boost_LIBRARIES Boost::program_options Boost::filesystem Boost::system)

# Include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Build example projects
add_subdirectory(example/analysis)
add_subdirectory(example/comparison)
add_subdirectory(example/email)
add_subdirectory(example/matching)
add_subdirectory(example/race)
add_subdirectory(example/report)

# Tests
add_subdirectory(tests)

# Target-specific settings
foreach(target IN ITEMS analysis comparison email matching race report tests)
    target_include_directories(${target} PRIVATE ${Boost_INCLUDE_DIR})
    target_link_libraries(${target} ${Boost_LIBRARIES})
endforeach()