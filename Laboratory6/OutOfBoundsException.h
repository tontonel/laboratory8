#pragma once
#include <exception>

class OutOfBoundsException
{
private:
	int firstIndex, lastIndex;
public:
	OutOfBoundsException(int firstIndex, int lastIndex);
	const char* what() const throw();
};

