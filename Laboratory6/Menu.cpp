#include "Menu.h"

Menu::Menu()
{
     this->validInput = { 'a', 's', 'p', 't', 'b', 'q', 'A', 'S', 'P', 'T', 'B', 'Q' };
}

void Menu::displayMenu() const
{
    std::cout << "A|a add an offer\nS|s show all offers\nP|p filter offers by price\nT|t filter offers by type\nB|b filter offers by type and price\nQ|q quit\n";
}

void Menu::displayOffers(DynamicArray<Offer>& offers) const
{
    std::cout << offers;
}

const float Menu::getPrice() const
{
    float price;
    std::cout << "ENTER PRICE: ";
    std::cin >> price;
    return price;
}

const typeOffer Menu::getType() const
{
    string input;
    std::cout << "Type:";
    std::cin >> input;
    typeOffer type;

    if (input == "circuit") type = circuit;
    else if (input == "cruise") type = cruise;
    else if (input == "all_inlcusive") type = all_inclusive;
    else if (input == "city_break") type = city_break;

    return type;
}

const char Menu::getTask() const
{
    char task;
    std::cout << "ENTER YOUR TASK: ";
    std::cin >> task;
    bool good = false;
    for (char a : validInput)
        if (task == a)
            good = true;
    if (good)
        return task;
    return '-1';
}

const Offer Menu::getOffer() const
{
	string id, departure, destination;
	unsigned int price;
	typeOffer type;
	string _type;

	std::cout << "ID:";
	std::cin >> id;

	std::cout << "Departure:";
    std::cin >> departure;

	std::cout << "Destination:";
    cin >> destination;

	std::cout << "Price:";
	std::cin >> price;
	if (price < 0) { std::cerr << "Price not valid!"; exit(-1); }

std:cout << "Starting date\n";
	unsigned int day, month, year;
	std::cout << "Day/Month/Year:"; std::cin >> day >> month >> year;
    string startDate = to_string(day) + '/' + to_string(month) + '/' + to_string(year);

	std::cout << "Ending date\n";
	std::cout << "Day/Month/Year:"; std::cin >> day >> month >> year;
    string endDate = to_string(day) + '/' + to_string(month) + '/' + to_string(year);

	std::cout << "Type:";
	std::cin >> _type;
	if (_type == "circuit") type = circuit;
	else if (_type == "cruise") type = cruise;
	else if (_type == "all_inlcusive") type = all_inclusive;
	else if (_type == "city_break") type = city_break;

	return Offer(id, departure, destination, price, startDate, endDate, type);
}

