#include <boost/test/unit_test.hpp>
#include <omi/types/timestamp.hpp>

// Regression tests for portable timestamp type
BOOST_AUTO_TEST_SUITE(TypesTimestamp)

BOOST_AUTO_TEST_CASE(VerifyDefaultConstructor) {
    auto timestamp = omi::timestamp();

    auto expected = 0;
    auto actual = timestamp.seconds();

    BOOST_CHECK_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_CASE(VerifyNowConstructor) {
    // Time when this test was written
    auto expected = omi::timestamp::seconds(1492308754);
    auto actual = omi::timestamp::now();

    BOOST_CHECK_LT(expected, actual);
}

BOOST_AUTO_TEST_CASE(VerifySecondsConstructor) {
    auto timstamp = omi::timestamp::seconds(2);

    auto expected = 2;
    auto actual = timstamp.seconds();

    BOOST_CHECK_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_CASE(VerifyMicrosecondsConstructor) {
    auto timstamp = omi::timestamp::microseconds(2000000);

    auto expected = 2;
    auto actual = timstamp.seconds();

    BOOST_CHECK_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_CASE(VerifyMillisecondsConstructor) {
    auto timstamp = omi::timestamp::milliseconds(2000);

    auto expected = 2;
    auto actual = timstamp.seconds();

    BOOST_CHECK_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_SUITE_END()