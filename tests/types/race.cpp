#include <omi/test/definitions.hpp>
#include <omi/types/race.hpp>

// Regression tests for race condition enum
BOOST_AUTO_TEST_SUITE(TypesRace)

using namespace omi;

BOOST_AUTO_TEST_CASE(VerifyDefaultConstructor) {
    auto comment = "Verify default constructor";

    auto expected = race::unknown;
    auto actual = race{};

    CHECK_EQUAL(expected, actual, comment);
}

///////////////////////

BOOST_AUTO_TEST_CASE(VerifyParseReturnValueFactor) {
    auto comment = "Verify parse 'factor' return value";

    auto expected = race::factor;
    auto actual = parse::race("factor");

    CHECK_EQUAL(expected, actual, comment);
}

BOOST_AUTO_TEST_CASE(VerifyParseReturnValueMicrosecond) {
    auto comment = "Verify parse 'MIN' return value";

    auto expected = race::minimum;
    auto actual = parse::race("MIN");

    CHECK_EQUAL(expected, actual, comment);
}

BOOST_AUTO_TEST_CASE(VerifyParseReturnValueMaximum) {
    auto comment = "Verify parse 'x' return value";

    auto expected = race::maximum;
    auto actual = parse::race("x");

    CHECK_EQUAL(expected, actual, comment);
}

BOOST_AUTO_TEST_CASE(VerifyParseReturnValueMinute) {
    auto comment = "Verify parse 'median' return value";

    auto expected = race::median;
    auto actual = parse::race("median");

    CHECK_EQUAL(expected, actual, comment);
}

///////////////////////

BOOST_AUTO_TEST_CASE(VerifyParseReturnValueUnknown) {
    auto comment = "Verify parse 'Hi Mom' return value";

    auto expected = race::unknown;
    auto actual = parse::race("Hi Mom");

    CHECK_EQUAL(expected, actual, comment);
}

BOOST_AUTO_TEST_CASE(VerifyParseReturnValueEmptyString) {
    auto comment = "Verify parse empty string return value";

    auto expected = race::unknown;
    auto actual = parse::race("");

    CHECK_EQUAL(expected, actual, comment);
}

BOOST_AUTO_TEST_SUITE_END()