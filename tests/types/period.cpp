#include <omi/test/definitions.hpp>
#include <omi/types/period.hpp>

// Regression tests for time period enum
BOOST_AUTO_TEST_SUITE(TypesPeriod)

using namespace omi;

BOOST_AUTO_TEST_CASE(VerifyDefaultConstructor) {
    auto comment = "Verify default constructor";

    auto expected = period::unknown;
    auto actual = period{};

    CHECK_EQUAL(expected, actual, comment);
}

///////////////////////

BOOST_AUTO_TEST_CASE(VerifyParseReturnValueNanosecond) {
    auto comment = "Verify parse 'nanosecond' returns period::nanosecond";

    auto expected = period::nanosecond;
    auto actual = parse::period("nanosecond");

    CHECK_EQUAL(expected, actual, comment);
}

BOOST_AUTO_TEST_CASE(VerifyParseReturnValueMicrosecond) {
    auto comment = "Verify parse 'microseconds' returns period::micosecond";

    auto expected = period::microsecond;
    auto actual = parse::period("microseconds");

    CHECK_EQUAL(expected, actual, comment);
}

BOOST_AUTO_TEST_CASE(VerifyParseReturnValueMillisecond) {
    auto comment = "Verify parse 'MILLI' returns period::millisecond";

    auto expected = period::millisecond;
    auto actual = parse::period("MILLI");

    CHECK_EQUAL(expected, actual, comment);
}

BOOST_AUTO_TEST_CASE(VerifyParseReturnValueSecond) {
    auto comment = "Verify parse 's' returns period::second";

    auto expected = period::second;
    auto actual = parse::period("s");

    CHECK_EQUAL(expected, actual, comment);
}

BOOST_AUTO_TEST_CASE(VerifyParseReturnValueMinute) {
    auto comment = "Verify parse 'minute' returns period::minute";

    auto expected = period::minute;
    auto actual = parse::period("minute");

    CHECK_EQUAL(expected, actual, comment);
}



///////////////////////

BOOST_AUTO_TEST_CASE(VerifyParseReturnValueUnknown) {
    auto comment = "Verify parse 'Hi Mom' returns period::unknown";

    auto expected = period::unknown;
    auto actual = parse::period("Hi Mom");

    CHECK_EQUAL(expected, actual, comment);
}

BOOST_AUTO_TEST_CASE(VerifyParseReturnValueEmptyString) {
    auto comment = "Verify parse empty string returns period::unknown";

    auto expected = period::unknown;
    auto actual = parse::period("");

    CHECK_EQUAL(expected, actual, comment);
}

BOOST_AUTO_TEST_SUITE_END()