#include "OutOfBoundsException.h"
#include <string>



OutOfBoundsException::OutOfBoundsException(int firstIndex, int lastIndex)
{
	this->firstIndex = firstIndex;
	this->lastIndex = lastIndex;
}

const char* OutOfBoundsException::what() const throw()
{
	std::string ans = "Out of bounds index 1:" + std::to_string(this->firstIndex) + "last index:" + std::to_string(this->lastIndex);
	return ans.c_str();
}
