#include <boost/test/unit_test.hpp>
#include <omi/types/sequence.hpp>

// Regression tests for portable timestamp type
BOOST_AUTO_TEST_SUITE(TypesSequence)

using namespace omi;

BOOST_AUTO_TEST_CASE(VerifyDefaultConstructor) {
    sequence sequence;

    auto expected = 0;
    auto actual = sequence.get();

    BOOST_CHECK_EQUAL(expected, actual);
}

///////////////////////

BOOST_AUTO_TEST_CASE(VerifyEqualsOperatoReturnsTrue) {
    auto condition = sequence{ 5 } == sequence{ 5 };

    BOOST_CHECK(condition);
}

BOOST_AUTO_TEST_CASE(VerifyEqualsOperatoReturnsFalse) {
    auto condition = sequence{ 5 } == sequence{ 6 };

    BOOST_CHECK(not condition);
}

///////////////////////

BOOST_AUTO_TEST_CASE(VerifyLessthanOperatoReturnsTrue) {
    auto condition = sequence{ 5 } < sequence{ 10 };

    BOOST_CHECK(condition);
}

BOOST_AUTO_TEST_CASE(VerifyOperatLessThanReturnsFalse) {
    auto comment = "Verify sequence type less than operator returns false";

    auto condition = sequence{ 10 } > sequence{ 6 };

    BOOST_CHECK_MESSAGE(not condition, comment);
}

BOOST_AUTO_TEST_SUITE_END()