#pragma once
#include "FilteringPrice.h"
#include "FilteringType.h"
#include "FilteringTypeAndPrice.h"
#include "DynamicArray.h"


class FilteringTest
{
public:
	static void runAllTests();
private:
	
	static void testFilterType();
	static void testFilterPrice();
	static void testFilterTypeandPrice();

};

