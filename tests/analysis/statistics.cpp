#include <boost/test/included/unit_test.hpp>
#include <omi/analysis/statistics.hpp>

// Unit tests for statistics
BOOST_AUTO_TEST_SUITE(AnalysisStatistics)

///////////////////////////////////

BOOST_AUTO_TEST_CASE(VerifyCount) {
    // Verify count after construction
    auto statistics = omi::analysis::statistics({1., 2., 3., 4.});

    // Verify value
    auto expected = 4;
    auto actual = statistics.count;

    BOOST_CHECK_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_CASE(VerifyCountEmptyList) {
    // Verify count for empty list
    auto statistics = omi::analysis::statistics({});

    // Verify value
    auto expected = 0.;
    auto actual = statistics.count;

    BOOST_CHECK_EQUAL(expected, actual);
}

///////////////////////////////////

BOOST_AUTO_TEST_CASE(VerifyAverage) {
    // Verify average
    auto statistics = omi::analysis::statistics({1., 2., 3.});

    // Verify value
    auto expected = 2.;
    auto actual = statistics.average;

    BOOST_CHECK_EQUAL(expected, actual);
}

///////////////////////////////////

BOOST_AUTO_TEST_CASE(VerifyStandardDeviation) {
    // Verify standard deviation

    auto statistics = omi::analysis::statistics({1., 2. });

    // Verify value
    auto expected = .5;
    auto actual = statistics.deviation;

    BOOST_CHECK_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_CASE(VerifyStandardDeviationEmptyList) {
    // Verify average for empty list
    auto statistics = omi::analysis::statistics({});

    // Verify value
    auto expected = 0.;
    auto actual = statistics.deviation;

    BOOST_CHECK_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_SUITE_END()
