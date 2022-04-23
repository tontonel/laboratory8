#include "DynamicArrayTest.h"
#include "DynamicArray.h"
#include <assert.h>

void DynamicArrayTest::runAllTests()
{
	testAppend();
	testGet();
	testGetCapacity;
	testGetLength();
	testPopBack();
	testRemove();
	std::cout << "Dynamic array tests passed:))\n";
}

void DynamicArrayTest::testGetLength()
{
	DynamicArray<Offer> arr;
	for (int i = 0; i < 10; i++)
		arr.append(Offer());
	assert(arr.getLength() == 10);
	arr.append(Offer());
	assert(arr.getLength() == 11);
	arr.popBack();
	arr.popBack();
	assert(arr.getLength() == 9);
}
void DynamicArrayTest::testGetCapacity()
{
	DynamicArray<Offer> arr;
	assert(arr.getCapacity() == 100);
	for (int i = 0; i < 102; i++)
		arr.append(Offer());
	assert(arr.getCapacity() == 200);
}

void DynamicArrayTest::testAppend()
{
	DynamicArray<Offer> arr;
	Offer offer = Offer("123", "Monday", "London", 130, "11/03/2021", "12/12/2021", circuit);
	arr.append(offer);
	assert(arr.popBack() == offer);
	for (int i = 0; i < 103; i++)
		arr.append(offer);
	assert(arr.popBack() == offer);
}

void DynamicArrayTest::testPopBack()
{
	DynamicArray<Offer> arr;
	for (int i = 0; i < 10; i++)
		arr.append(Offer());
	arr.popBack();
	assert(arr.getLength() == 9);
	Offer offer = Offer("123", "Monday", "London", 130, "11/03/2021", "12/12/2021", circuit);
	arr.append(offer);
	assert(arr.popBack() == offer);

}

void DynamicArrayTest::testRemove()
{
	DynamicArray<Offer> arr;
	for (int i = 1; i <= 10; i++)
		arr.append(Offer());
	arr.remove(4);
	assert(arr.getLength() == 9);
	DynamicArray<Offer> arr1;
	Offer offer1 = Offer("123", "Monday", "London", 130, "11/03/2021", "12/12/2021", circuit);
	Offer offer2 = Offer("123", "Monday", "London", 130, "11/03/2021", "12/12/2021", circuit);
	arr1.append(offer1);
	arr1.append(offer2);
	arr1.remove(1);
	assert(arr1.popBack() == offer1);
}

void DynamicArrayTest::testGet()
{
	Offer offer1 = Offer("123", "Monday", "London", 130, "11/03/2021", "12/12/2021", circuit);
	Offer offer2 = Offer("123", "Monday", "London", 130, "11/03/2021", "12/12/2021", circuit);
	Offer offer3 = Offer("123", "Monday", "London", 130, "11/03/2021", "12/12/2021", city_break);
	DynamicArray<Offer> arr;
	arr.append(offer1);
	arr.append(offer2);
	arr.append(offer3);
	assert(arr.get(2) == offer3);
	assert(arr.get(0) == offer1);
	arr.remove(1);
	assert(arr.get(1) == offer3);
}
