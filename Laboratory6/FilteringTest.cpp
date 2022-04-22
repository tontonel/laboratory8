#include "FilteringTest.h"
#include "Offer.h"
#include <assert.h>

void FilteringTest::runAllTests()
{
	testFilterPrice();
	testFilterType();
	testFilterTypeandPrice();
	std::cout << "All filter tests passed:))\n";
}

void FilteringTest::testFilterType()
{
	DynamicArray arr;
	arr.append(Offer("213", "tuesday", "Paris", 140, "14.01.2020", "14.03.2020", city_break));
	arr.append(Offer("123", "Monday", "London", 130, "11/03/2021", "12/12/2021", circuit));
	arr.append(Offer("123", "Monday", "London", 130, "11/03/2021", "12/12/2021", circuit));
	arr.append(Offer("253", "friday", "Muchen", 140, "14.01.2023", "14.03.2027", city_break));
	DynamicArray newArr = FilteringType(city_break).filter(arr);
	assert(newArr.getLength() == 2);
	assert(newArr.popBack() == Offer("253", "friday", "Muchen", 140, "14.01.2023", "14.03.2027", city_break));
}

void FilteringTest::testFilterPrice()
{
	DynamicArray arr;
	arr.append(Offer("213", "tuesday", "Paris", 140, "14.01.2020", "14.03.2020", city_break));
	arr.append(Offer("123", "Monday", "London", 130, "11/03/2021", "12/12/2021", circuit));
	arr.append(Offer("123", "Monday", "London", 130, "11/03/2021", "12/12/2021", circuit));
	arr.append(Offer("213", "friday", "Muchen", 140, "14.01.2023", "14.03.2027", city_break));
	DynamicArray newArr = FilteringPrice(135).filter(arr);
	assert(newArr.getLength() == 2);
	assert(newArr.get(1) == Offer("123", "Monday", "London", 130, "11/03/2021", "12/12/2021", circuit));
}

void FilteringTest::testFilterTypeandPrice()
{
	DynamicArray arr;
	arr.append(Offer("213", "tuesday", "Paris", 130, "14.01.2020", "14.03.2020", city_break));
	arr.append(Offer("123", "Monday", "London", 130, "11/03/2021", "12/12/2021", circuit));
	arr.append(Offer("123", "Monday", "London", 140, "11/03/2021", "12/12/2021", circuit));
	arr.append(Offer("213", "friday", "Muchen", 140, "14.01.2023", "14.03.2027", city_break));
	DynamicArray newArr = FilteringTypeAndPrice(circuit, 135).filter(arr);
	assert(newArr.getLength() == 1);
	assert(newArr.get(0) == Offer("123", "Monday", "London", 130, "11/03/2021", "12/12/2021", circuit));
}
