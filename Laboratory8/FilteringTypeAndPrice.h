#pragma once
#include "FilteringCriteria.h"
#include "FilteringPrice.h"
#include "FilteringType.h"

class FilteringTypeAndPrice : public FilteringCriteria
{
private:
	typeOffer type;
	int price;
public:
	FilteringTypeAndPrice(typeOffer type, int price);
	DynamicArray filter(DynamicArray& data);
};

