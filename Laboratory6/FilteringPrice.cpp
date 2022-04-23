#include "FilteringPrice.h"

FilteringPrice::FilteringPrice(int price):FilteringCriteria()
{
    this->price = price;
}

DynamicArray FilteringPrice::filter(DynamicArray& data)
{
    DynamicArray new_data = DynamicArray();
    for (int i = 0; i < data.getLength(); i++) {
        if (data.get(i).getPrice() < this->price)
            new_data.append(data.get(i));
    }
    return new_data;
}
