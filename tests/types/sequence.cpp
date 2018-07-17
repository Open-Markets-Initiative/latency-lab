#include <omi/test/definitions.hpp>
#include <omi/types/seqnum.hpp>

// Regression tests for portable sequence number type
BOOST_AUTO_TEST_SUITE(TypesSequence)

using namespace omi;

BOOST_AUTO_TEST_CASE(VerifyDefaultConstructor) {
    auto comment = "Verify default constructor";

    seqnum sequence;

    auto expected = 0;
    auto actual = sequence.get();

    CHECK_EQUAL(expected, actual, comment);
}

///////////////////////

BOOST_AUTO_TEST_CASE(VerifyEqualsOperatoReturnsTrue) {
    auto comment = "Verify sequence equals operator returns true";

    auto condition = seqnum{ 5 } == seqnum{ 5 };

    BOOST_CHECK_MESSAGE(condition, comment);
}

BOOST_AUTO_TEST_CASE(VerifyEqualsOperatoReturnsFalse) {
    auto comment = "Verify sequence equals operator returns false";

    auto condition = seqnum{ 5 } == seqnum{ 6 };

    BOOST_CHECK_MESSAGE(not condition, comment);
}

///////////////////////

BOOST_AUTO_TEST_CASE(VerifyLessthanOperatoReturnsTrue) {
    auto comment = "Verify sequence type less than operator returns true";

    auto condition = seqnum{ 5 } < seqnum{ 10 };

    BOOST_CHECK_MESSAGE(condition, comment);
}

BOOST_AUTO_TEST_CASE(VerifyOperatLessThanReturnsFalse) {
    auto comment = "Verify sequence type less than operator returns false";

    auto condition = seqnum{ 1 } > seqnum{ 6 };

    BOOST_CHECK_MESSAGE(not condition, comment);
}

BOOST_AUTO_TEST_SUITE_END()