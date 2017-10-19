#include <boost/test/unit_test.hpp>
#include <omi/types/timestamp.hpp>

// Regression tests for portable timestamp type
BOOST_AUTO_TEST_SUITE(TypesTimestamp)

using namespace omi;

BOOST_AUTO_TEST_CASE(VerifyDefaultConstructor) {
    timestamp timestamp{};

    auto expected = 0;
    auto actual = timestamp.seconds();

    BOOST_CHECK_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_CASE(VerifyNowConstructor) {
    // Time when this test was written
    auto expected = timestamp::seconds(1492308754);
    auto actual = timestamp::now();

    BOOST_CHECK_LT(expected, actual);
}

BOOST_AUTO_TEST_CASE(VerifySecondsConstructor) {
    auto timstamp = timestamp::seconds(2);

    auto expected = 2;
    auto actual = timstamp.seconds();

    BOOST_CHECK_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_CASE(VerifyMicrosecondsConstructor) {
    auto timstamp = timestamp::microseconds(2000000);

    auto expected = 2;
    auto actual = timstamp.seconds();

    BOOST_CHECK_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_CASE(VerifyMillisecondsConstructor) {
    auto timstamp = timestamp::milliseconds(2000);

    auto expected = 2;
    auto actual = timstamp.seconds();

    BOOST_CHECK_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_SUITE_END()
