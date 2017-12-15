#include <omi/test/definitions.hpp>
#include <omi/collection/percentile.hpp>

// Unit tests for percentile
BOOST_AUTO_TEST_SUITE(CollectionPercentile)

using namespace omi;

///////////////////////////////////////////////
// collection::index()

BOOST_AUTO_TEST_CASE(VerifyIndexZeroReturnValue) {
    auto comment = "Verify collection::index() return value for 0";

    auto expected = 0;
    auto actual = collection::index(0, 1);

    CHECK_EQUAL(expected, actual, comment);
}

BOOST_AUTO_TEST_CASE(VerifyIndexLessThanOneHundredReturnValue) {
    auto comment = "Verify collection::index() return value for Less than 100";

    auto expected = 0;
    auto actual = collection::index(50, 1);

    CHECK_EQUAL(expected, actual, comment);
}

BOOST_AUTO_TEST_CASE(VerifyIndexReturnValueOne) {
    auto comment = "Verify collection::index() return value 1";

    auto expected = 0;
    auto actual = collection::index(100, 1);

    CHECK_EQUAL(expected, actual, comment);
}

BOOST_AUTO_TEST_CASE(VerifyIndexReturnValueTen) {
    auto comment = "Verify percentile::index() return value 10";

    auto expected = 9; // 0 based
    auto actual = collection::index(100, 10);

    CHECK_EQUAL(expected, actual, comment);
}

///////////////////////////////////////////////
// collection::percentile()

BOOST_AUTO_TEST_CASE(VerifyElementZeroReturnValue) {
    auto comment = "Verify collection::percentile() return value for first element";

    auto vector = std::vector<double>{ 0.0, 0.0, 0.0, 0.0 };

    auto expected = 0.0;
    auto actual = collection::percentile(0, vector);

    CHECK_EQUAL(expected, actual, comment);
}

BOOST_AUTO_TEST_CASE(VerifyElementMinReturnValue) {
    auto comment = "Verify collection::percentile() return value for minimum";

    auto vector = std::vector<double>{ 0.0, 1.0, 2.0, 3.0 };

    auto expected = 0.0;
    auto actual = collection::percentile(0, vector);

    CHECK_EQUAL(expected, actual, comment);
}

BOOST_AUTO_TEST_SUITE_END()