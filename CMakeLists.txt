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
target_include_directories(analysis PRIVATE ${Boost_INCLUDE_DIRS})
target_link_libraries(analysis PRIVATE Boost::program_options Boost::filesystem Boost::system)

target_include_directories(comparison PRIVATE ${Boost_INCLUDE_DIRS})
target_link_libraries(comparison PRIVATE Boost::program_options Boost::filesystem Boost::system)

target_include_directories(email PRIVATE ${Boost_INCLUDE_DIRS})
target_link_libraries(email PRIVATE Boost::program_options Boost::filesystem Boost::system)

target_include_directories(matching PRIVATE ${Boost_INCLUDE_DIRS})
target_link_libraries(matching PRIVATE Boost::program_options Boost::filesystem Boost::system)

target_include_directories(race PRIVATE ${Boost_INCLUDE_DIRS})
target_link_libraries(race PRIVATE Boost::program_options Boost::filesystem Boost::system)

target_include_directories(report PRIVATE ${Boost_INCLUDE_DIRS})
target_link_libraries(report PRIVATE Boost::program_options Boost::filesystem Boost::system)

target_include_directories(tests PRIVATE ${Boost_INCLUDE_DIRS})
target_link_libraries(tests PRIVATE Boost::program_options Boost::filesystem Boost::system)
