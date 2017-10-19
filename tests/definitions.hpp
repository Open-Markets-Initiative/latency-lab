#ifndef OMI_TESTS_HPP_
#define OMI_TESTS_HPP_

#include <boost/test/unit_test.hpp>

#define CHECK_EQUAL(Expected, Actual, Message) { BOOST_TEST_INFO(Message); BOOST_CHECK_EQUAL(Expected, Actual); }
#define WARN_EQUAL(L, R, M) { BOOST_TEST_INFO(M); BOOST_WARN_EQUAL(L, R); }
#define REQUIRE_EQUAL(L, R, M) { BOOST_TEST_INFO(M); BOOST_REQUIRE_EQUAL(L, R); }

#endif