#include "easyfind.hpp"
#include <list>
#include <iostream>


int main(void)
{
	std::list<int> lst;
	
	for (int i = 0; i < 10; i++)
		lst.push_back(i);

	if (easyfind(lst, 5) != lst.end())
		std::cout << "Value found" << std::endl;
	else
		std::cout << "Value not found" << std::endl;
	if (easyfind(lst, 10) != lst.end())
		std::cout << "Value found" << std::endl;
	else
		std::cout << "Value not found" << std::endl;


}