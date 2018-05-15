#include <omi/test/definitions.hpp>
#include <omi/collection/calculate.hpp>

#include <vector>
#include <list>

// Unit tests for percentile
BOOST_AUTO_TEST_SUITE(CollectionCalculate)

using namespace omi;

///////////////////////////////////////////////
// collection::sum()

BOOST_AUTO_TEST_CASE(VerifySumReturnValue) {
    auto comment = "Verify collection::sum() return value for 0, 1, 2, 3";

    auto expected = 6;
    auto actual = collection::sum(std::vector<int>{ 0, 1, 2, 3 });

    CHECK_EQUAL(expected, actual, comment);
}

BOOST_AUTO_TEST_CASE(VerifySumEmptyReturnValue) {
    auto comment = "Verify collection::sum() return value for empty list";

    auto expected = 0.;
    auto actual = collection::sum(std::list<double>{});

    CHECK_EQUAL(expected, actual, comment);
}

BOOST_AUTO_TEST_SUITE_END()