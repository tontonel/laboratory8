#pragma once
#include "FilteringCriteria.h"
#include "DynamicArray.h"


class FilteringPrice : public FilteringCriteria
{
private:
	int price;
public:
	FilteringPrice(int price);
	DynamicArray filter(DynamicArray& data) override;
};

