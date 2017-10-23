#include <omi/test/definitions.hpp>
#include <omi/analysis/percentiles.hpp>

// Unit tests for percentiles
BOOST_AUTO_TEST_SUITE(AnalysisPercentiles)

using namespace omi;

BOOST_AUTO_TEST_CASE(VerifyCount) {
    auto comment = "Verify value count";

    // Initialize data
    auto values = std::vector<double>{ 10, 20, 30, 100 };
    auto percentiles = analysis::percentiles<>{ values };

    // Verify value
    auto expected = values.size();
    auto actual = percentiles.count;

    CHECK_EQUAL(expected, actual, comment);
}

///////////////////////////////////

BOOST_AUTO_TEST_CASE(Verify0thPercentile) {
    auto comment = "Verify value count";

    // Initialize data
    auto values = std::vector<double>{ 10, 20, 30, 100 };
    auto percentiles = analysis::percentiles<>{ values };

    // Verify value
    auto expected = 10.;
    auto actual = percentiles.p00;

    CHECK_EQUAL(expected, actual, comment);
}

BOOST_AUTO_TEST_CASE(VerifyDefault0thPercentile) {
    auto comment = "Verify value 0th percentile default value";

    // Initialize data
    analysis::percentiles<> percentiles;

    // Verify value
    auto expected = 0.;
    auto actual = percentiles.p00;

    CHECK_EQUAL(expected, actual, comment);
}

///////////////////////////////////

BOOST_AUTO_TEST_CASE(Verify100thPercentile) {
    auto comment = "Verify 100th percentile value";

    // Initialize data
    auto values = std::vector<double>{ 10, 20, 30, 100 };
    auto percentiles = analysis::percentiles<>{ values };

    // Verify value
    auto expected = 100.;
    auto actual = percentiles.p100;

    CHECK_EQUAL(expected, actual, comment);
}

BOOST_AUTO_TEST_SUITE_END()