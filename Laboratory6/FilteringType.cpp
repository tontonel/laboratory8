#include "FilteringType.h"

FilteringType::FilteringType(typeOffer type) : FilteringCriteria()
{
	this->type = type;
}

DynamicArray FilteringType::filter(DynamicArray& data)
{
	DynamicArray new_data = DynamicArray();
	for (int i = 0; i < data.getLength(); i++) {
		if (data.get(i).getType() == type)
			new_data.append(data.get(i));
	}
	return new_data;
}
