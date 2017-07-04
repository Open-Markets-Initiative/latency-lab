#include <boost/test/unit_test.hpp>
#include <omi/analysis/percentiles.hpp>

// Unit tests for percentiles
BOOST_AUTO_TEST_SUITE(AnalysisPercentiles)

BOOST_AUTO_TEST_CASE(VerifyCount) {
	// Initialize data
	auto values = std::vector<double>{ 10, 20, 30, 100 };
	auto percentiles = omi::analysis::percentiles{ values };

	// Verify value
	auto expected = values.size();
	auto actual = percentiles.count;

	BOOST_CHECK_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_CASE(Verify100thPercentile) {
	// Initialize data
	auto values = std::vector<double>{ 10, 20, 30, 100 };
	auto percentiles = omi::analysis::percentiles{ values };

	// Verify value
	auto expected = 100;
	auto actual = percentiles.p100;

	BOOST_CHECK_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_SUITE_END()