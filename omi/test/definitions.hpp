#ifndef OMI_TEST_DEFINITIONS_HPP_
#define OMI_TEST_DEFINITIONS_HPP_

#include <boost/test/unit_test.hpp>

#define CHECK_EQUAL(Expected, Actual, Message) { BOOST_TEST_INFO(Message); BOOST_CHECK_EQUAL(Expected, Actual); }
#define WARN_EQUAL(Expected, Actual, Message) { BOOST_TEST_INFO(Message); BOOST_WARN_EQUAL(Expected, Actual); }
#define REQUIRE_EQUAL(Expected, Actual, Message) { BOOST_TEST_INFO(Message); BOOST_REQUIRE_EQUAL(Expected, Actual); }

#endif