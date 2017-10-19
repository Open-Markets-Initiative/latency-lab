add_executable(testAnalysisPercentile test/main.cpp analysis/percentile.cpp)
target_link_libraries(testAnalysisPercentile ${Boost_LIBRARIES})
add_test(NAME test_Analysis_Percentile COMMAND testAnalysisPercentile)

add_executable(testAnalysisPercentiles test/main.cpp analysis/percentiles.cpp)
target_link_libraries(testAnalysisPercentiles ${Boost_LIBRARIES})
add_test(NAME test_Analysis_Percentiles COMMAND testAnalysisPercentiles)

add_executable(testAnalysisStatistics test/main.cpp analysis/statistics.cpp)
target_link_libraries(testAnalysisStatistics ${Boost_LIBRARIES})
add_test(NAME test_Analysis_Statistics COMMAND testAnalysisStatistics)

add_executable(testTypesSequence test/main.cpp types/sequence.cpp)
target_link_libraries(testTypesSequence ${Boost_LIBRARIES})
add_test(NAME test_Types_Sequence COMMAND testTypesSequence)

add_executable(testTypesTimestamp test/main.cpp types/timestamp.cpp)
target_link_libraries(testTypesTimestamp ${Boost_LIBRARIES})
add_test(NAME test_Types_Timestamp COMMAND testTypesTimestamp)
