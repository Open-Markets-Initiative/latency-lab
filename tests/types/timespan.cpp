#include <omi/test/definitions.hpp>
#include <omi/types/timespan.hpp>

// Regression tests for portable timespan type
BOOST_AUTO_TEST_SUITE(TypesTimespan)

using namespace omi;

BOOST_AUTO_TEST_CASE(VerifyDefaultConstructor) {
    auto comment = "Verify default constructor";

    timespan timespan;

    auto expected = 0;
    auto actual = timespan.seconds();

    CHECK_EQUAL(expected, actual, comment);
}

BOOST_AUTO_TEST_CASE(VerifyMicrosecondsConstructor) {
    auto comment = "Verify microseconds static constructor";

    auto timestamp = timespan::microseconds(2000000);

    auto expected = 2;
    auto actual = timestamp.seconds();

    CHECK_EQUAL(expected, actual, comment);
}

BOOST_AUTO_TEST_CASE(VerifyMillisecondsConstructor) {
    auto comment = "Verify milliseconds static constructor";

    auto timestamp = timespan::milliseconds(2000);

    auto expected = 2;
    auto actual = timestamp.seconds();

    CHECK_EQUAL(expected, actual, comment);
}

BOOST_AUTO_TEST_CASE(VerifySecondsConstructor) {
    auto comment = "Verify seconds static constructor";

    auto timespan = timespan::seconds(2);

    auto expected = 2;
    auto actual = timespan.seconds();

    CHECK_EQUAL(expected, actual, comment);
}

BOOST_AUTO_TEST_SUITE_END()