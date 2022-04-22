#include "Offer.h"
#include <string>

Offer::Offer():
	id { 1 },
	departure{ "NONE" },
	destionation{ "NONE" },
	price{ 0 },
	start_date{"NONE"},
	end_date{"NONE"},
	type{circuit}
{}

Offer::Offer(std::string _id, std::string _destionation, std::string _departure,
	int _price, std::string _start_date, std::string _end_date, typeOffer  _type):
	id{_id},
	departure{_departure},
	destionation{ _destionation },
	price{ _price },
	start_date{ _start_date },
	end_date{_end_date},
	type{_type}
	{}

const float& Offer::getPrice() const
{
	return this->price;
}


const typeOffer& Offer::getType() const
{
	return this->type;
}



bool operator==(const Offer& offer1, const Offer& offer2)
{
	return offer1.id == offer2.id;
}

std::ostream& operator<<(std::ostream& out, const Offer& offer)
{
	out << "ID: " << offer.id << "\nPRICE: " << offer.price << "\nTYPE: " << offer.type << "\nDESTINATION: "
		<< offer.destionation << "\nSTART DATE: " << offer.start_date << "\nEND DATE: " << offer.end_date << "\n";
	return out;
}
