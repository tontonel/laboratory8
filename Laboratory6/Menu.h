#pragma once
#include "Offer.h"
#include <vector>
#include <string>
#include <iostream>
#include "DynamicArray.h"

class Menu
{
public:
	Menu();
	void displayMenu() const;
	void displayOffers(DynamicArray<Offer>&) const;
	const float getPrice() const;
	const typeOffer getType() const;
	const char getTask() const;
	const Offer getOffer() const;

private:
	std::vector<char> validInput;
};

