#include <omi/test/definitions.hpp>
#include <omi/types/timestamp.hpp>

// Regression tests for portable timestamp type
BOOST_AUTO_TEST_SUITE(TypesTimestamp)

using namespace omi;

BOOST_AUTO_TEST_CASE(VerifyDefaultConstructor) {
    auto comment = "Verify default constructor";

    timestamp timestamp;

    auto expected = 0;
    auto actual = timestamp.seconds();

    CHECK_EQUAL(expected, actual, comment);
}

BOOST_AUTO_TEST_CASE(VerifyNowConstructor) {
    auto comment = "Verify now constructor";

    // Time when this test was written
    auto then = timestamp::seconds(1492308754);
    auto condition = then < timestamp::now();

    BOOST_CHECK_MESSAGE(condition, comment);
}

///////////////////////////////////

BOOST_AUTO_TEST_CASE(VerifyMicrosecondsConstructor) {
    auto comment = "Verify microseconds static constructor";

    auto timestamp = timestamp::microseconds(2000000);

    auto expected = 2;
    auto actual = timestamp.seconds();

    CHECK_EQUAL(expected, actual, comment);
}

BOOST_AUTO_TEST_CASE(VerifyMillisecondsConstructor) {
    auto comment = "Verify milliseconds static constructor";

    auto timestamp = timestamp::milliseconds(2000);

    auto expected = 2;
    auto actual = timestamp.seconds();

    CHECK_EQUAL(expected, actual, comment);
}

BOOST_AUTO_TEST_CASE(VerifySecondsConstructor) {
    auto comment = "Verify seconds static constructor";

    auto timstamp = timestamp::seconds(2);

    auto expected = 2;
    auto actual = timstamp.seconds();

    CHECK_EQUAL(expected, actual, comment);
}

BOOST_AUTO_TEST_SUITE_END()