#include "OfferTest.h"
#include <assert.h>

void OfferTest::runAllTests()
{
	testGetPrice();
	testGetType();
	std::cout << "Offer tests passed:))\n";
}

void OfferTest::testGetPrice()
{
	Offer offer1 = Offer("123", "sunday", "London", 123, "12.02.2020", "10.05.2020", circuit);
	assert(offer1.getPrice() == 123);
}

void OfferTest::testGetType()
{
	Offer offer1 = Offer("123", "sunday", "London", 123, "12.02.2020", "10.05.2020", circuit);
	assert(offer1.getType() == circuit);
}
