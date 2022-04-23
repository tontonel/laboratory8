#include "FilteringType.h"

FilteringType::FilteringType(typeOffer type) : FilteringCriteria()
{
	this->type = type;
}

DynamicArray<Offer> FilteringType::filter(DynamicArray<Offer>& data)
{
	DynamicArray<Offer> new_data = DynamicArray<Offer>();
	for (int i = 0; i < data.getLength(); i++) {
		if (data.get(i).getType() == type)
			new_data.append(data.get(i));
	}
	return new_data;
}
