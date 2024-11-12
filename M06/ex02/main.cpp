#include "Classes.hpp"
#include "Functions.hpp"
#include <iostream>

int main(void)
{
	for (int i = 0; i < 10; i++)
	{
		std::cout << "----------------------" << std::endl;
		Base *base = generate();
		identify(base);
		identify(*base);
		delete base;
		std::cout << "----------------------\n" << std::endl;
	}
	return 0;
}