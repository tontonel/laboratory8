#include "FilteringTypeAndPrice.h"

FilteringTypeAndPrice::FilteringTypeAndPrice(typeOffer type, int price) : FilteringCriteria()
{
	this->type = type;
	this->price = price;
}

DynamicArray<Offer> FilteringTypeAndPrice::filter(DynamicArray<Offer>& data)
{
	DynamicArray<Offer> new_data;
	new_data = FilteringType(this->type).filter(data);
	new_data = FilteringPrice(this->price).filter(new_data);
	return new_data;
}
