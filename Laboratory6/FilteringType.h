#pragma once
#include "FilteringCriteria.h"


class FilteringType : public FilteringCriteria
{
private: typeOffer type;
	
public:
	FilteringType(typeOffer type);
	DynamicArray filter(DynamicArray& data) override;
};

