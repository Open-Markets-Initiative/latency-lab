#include <omi/test/definitions.hpp>
#include <omi/analysis/statistics.hpp>

// Regression tests for statistics
BOOST_AUTO_TEST_SUITE(AnalysisStatistics)

using namespace omi;

///////////////////////////////////

BOOST_AUTO_TEST_CASE(VerifyCount) {
    auto comment = "Verify count after construction";

    auto statistics = analysis::statistics({1., 2., 3., 4.});

    // Verify value
    auto expected = 4;
    auto actual = statistics.count;

    CHECK_EQUAL(expected, actual, comment);
}

BOOST_AUTO_TEST_CASE(VerifyCountEmptyList) {
    auto comment = "Verify count for empty list";

    // Construct from empty list
    auto empty = std::vector<double>{};
    auto statistics = analysis::statistics(empty);

    // Verify value
    auto expected = 0.;
    auto actual = statistics.count;

    CHECK_EQUAL(expected, actual, comment);
}

///////////////////////////////////

BOOST_AUTO_TEST_CASE(VerifyAverage) {
    auto comment = "Verify statistics average";

    auto statistics = analysis::statistics({1., 2., 3.});

    auto expected = 2.;
    auto actual = statistics.average;

    CHECK_EQUAL(expected, actual, comment);
}

BOOST_AUTO_TEST_CASE(VerifyAverageEmptyList) {
    auto comment = "Verify statistics average for empty list";

    // Verify average for empty list
    auto empty = std::vector<double>{};
    auto statistics = analysis::statistics(empty);

    // Verify value
    auto expected = 0.;
    auto actual = statistics.average;

    CHECK_EQUAL(expected, actual, comment);
}

///////////////////////////////////

BOOST_AUTO_TEST_CASE(VerifyStandardDeviation) {
    auto comment = "Verify statistics standard deviation";

    // Calculate statistics
    auto statistics = analysis::statistics({1., 2. });

    // Verify value
    auto expected = .5;
    auto actual = statistics.deviation;

    CHECK_EQUAL(expected, actual, comment);
}

BOOST_AUTO_TEST_CASE(VerifyStandardDeviationEmptyList) {
    auto comment = "Verify statistics standard deviation for empty list";

    // Calculate statistics
    auto empty = std::vector<double>{};
    auto statistics = analysis::statistics(empty);

    // Verify value
    auto expected = 0.;
    auto actual = statistics.deviation;

    CHECK_EQUAL(expected, actual, comment);
}

BOOST_AUTO_TEST_SUITE_END()