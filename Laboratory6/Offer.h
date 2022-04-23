#pragma once
#include <string>
#include <iostream>

enum typeOffer {
	city_break,
	circuit,
	cruise,
	all_inclusive
};

class Offer
{
private:
	std::string id;
	std::string departure;
	std::string destionation;
	int price;
	std::string start_date;
	std::string end_date;
	typeOffer type;
public:
	Offer();
	Offer(std::string _id, std::string destionation, std::string departure,
		int price, std::string start_date, std::string end_date, typeOffer type);
	const float& getPrice() const;
	const typeOffer& getType() const;
	friend std::ostream& operator<< (std::ostream& out, const Offer& offer);
	friend bool operator==(const Offer& offer1, const Offer& offer2);

};

