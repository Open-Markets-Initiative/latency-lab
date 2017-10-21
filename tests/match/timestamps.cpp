#include <omi/test/definitions.hpp>
#include <omi/test/event.hpp>
#include <omi/match/timestamps.hpp>

// Regression tests for match timestamps
BOOST_AUTO_TEST_SUITE(MatchTimestamps)

using namespace omi;

BOOST_AUTO_TEST_CASE(VerifyConstructorSetsDefaultTrigger) {
    auto comment = "Verify standard constructor sets trigger time";

    test::event inbound, outbound;
    auto time = match::timestamps<test::event, test::event>{inbound, outbound};

    auto expected = timestamp{ 0 };
    auto actual = time.trigger;

    CHECK_EQUAL(expected, actual, comment);
}

BOOST_AUTO_TEST_CASE(VerifyConstructorSetsDefaultResponse) {
    auto comment = "Verify standard constructor sets response time";

    test::event inbound, outbound;
    auto time = match::timestamps<test::event, test::event>{ inbound, outbound };

    auto expected = timestamp{ 0 };
    auto actual = time.response;

    CHECK_EQUAL(expected, actual, comment);
}

///////////////////////////////////////////////

BOOST_AUTO_TEST_CASE(VerifyDelta) {
    auto comment = "Verify delta";

    test::event trigger;
      trigger.timestamp = timestamp{ 100 };
    test::event response;
      response.timestamp = timestamp{ 200 };

    auto time = match::timestamps<test::event, test::event>{ trigger, response };

    auto expected = timestamp{ 100 };
    auto actual = time.delta();

    CHECK_EQUAL(expected, actual, comment);
}

BOOST_AUTO_TEST_SUITE_END()