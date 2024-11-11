#ifndef DATA_H
# define DATA_H

#include <string>
#include <iostream>

struct Data
{
	int number;
	std::string text;
};

std::ostream& operator<<(std::ostream& os, const Data& data);



#endif