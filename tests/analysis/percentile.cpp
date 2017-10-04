#include <boost/test/included/unit_test.hpp>
#include <omi/analysis/percentile.hpp>

// Unit tests for percentile
BOOST_AUTO_TEST_SUITE(AnalysisPercentile)

BOOST_AUTO_TEST_CASE(VerifyIndexZeroReturnValue) {
    // Verify percentile::index() return value";
    auto expected = 0;
    auto actual = omi::analysis::percentile::index(0, 1);

    BOOST_CHECK_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_CASE(VerifyIndexLessThanOneHundredReturnValue) {
    // Verify percentile::index() return value";
    auto expected = 0;
    auto actual = omi::analysis::percentile::index(50, 1);

    BOOST_CHECK_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_CASE(VerifyIndexReturnValueOne) {
    // Verify value
    auto expected = 0;
    auto actual = omi::analysis::percentile::index(100, 1);

    BOOST_CHECK_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_CASE(VerifyIndexReturnValueTen) {
    // Verify value
    auto expected = 9; // 0 based
    auto actual = omi::analysis::percentile::index(100, 10);

    BOOST_CHECK_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_CASE(VerifyElementZeroReturnValue) {
    // Verify value
    auto expected = 0.0; // 0 based
    auto vector = std::vector<double>{0.0, 0.0, 0.0, 0.0};
    auto actual = omi::analysis::percentile::element(vector, 0.0);

    BOOST_CHECK_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_SUITE_END()
