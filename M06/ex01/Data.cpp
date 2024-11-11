#include "Data.hpp"

std::ostream &operator<<(std::ostream &os, const Data &data)
{
	std::cout << "{ number: " << data.number << ", text: " << data.text << " }";
	return os;
}
