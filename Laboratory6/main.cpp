#include "OfferTest.h"
#include "FilteringTest.h"
#include "DynamicArrayTest.h"
#include "Menu.h"
#include "Offer.h"
#include "FilteringPrice.h"
#include "FilteringType.h"
#include "FilteringTypeAndPrice.h"

#include <iostream>



void displayMenu() {
}

int main() {

	OfferTest::runAllTests();
	FilteringTest::runAllTests();
	DynamicArrayTest::runAllTests();

	
	DynamicArray offers;
	Offer offer;
	Menu menu;

	float price;
	typeOffer type;

	while (true) {
		menu.displayMenu();
		char task = menu.getTask();
		if (task == '-1') continue;



		switch (task) {
		case 'a':
			offer = menu.getOffer();
			offers.append(offer);
			break;

		case 's':
			menu.displayOffers(offers);
			break;

		case 'p': {
			price = menu.getPrice();
			offers = FilteringPrice(price).filter(offers);
		}
				break;

		case 't':
			type = menu.getType();
			offers = FilteringType(type).filter(offers);
			break;

		case 'b': {
			price = menu.getPrice();
			type = menu.getType();
			offers = FilteringTypeAndPrice(type, price).filter(offers);
		}
				break;

		case 'q':
			exit(0);
		}
	}
	return 0;
}