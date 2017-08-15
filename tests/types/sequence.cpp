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

BOOST_AUTO_TEST_CASE(VerifyEqualsOperatoReturnsTrue) {
    auto condition = sequence{ 5 } == sequence{ 5 };

    BOOST_CHECK(condition);
}

BOOST_AUTO_TEST_SUITE_END()