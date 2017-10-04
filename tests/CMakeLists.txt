add_executable(testAnalysisPercentile tests.cpp analysis/percentile.cpp)
target_link_libraries(testAnalysisPercentile ${Boost_LIBRARIES})
add_test(NAME test_Analysis_Percentile COMMAND testAnalysisPercentile)

add_executable(testAnalysisPercentiles tests.cpp analysis/percentiles.cpp)
target_link_libraries(testAnalysisPercentiles ${Boost_LIBRARIES})
add_test(NAME test_Analysis_Percentiles COMMAND testAnalysisPercentiles)
