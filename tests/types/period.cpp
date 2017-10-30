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

BOOST_AUTO_TEST_SUITE_END()