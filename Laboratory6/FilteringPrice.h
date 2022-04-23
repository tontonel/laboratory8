#pragma once
#include "FilteringCriteria.h"
#include "DynamicArray.h"


class FilteringPrice : public FilteringCriteria
{
private:
	int price;
public:
	FilteringPrice(int price);
	DynamicArray<Offer> filter(DynamicArray<Offer>& data) override;
};

