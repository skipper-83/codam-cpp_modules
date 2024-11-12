#include "Classes.hpp"
#include "Functions.hpp"
#include <math.h>
#include <iostream>

Base *generate(void)
{
	static int seed = 0; 
	srand(time(NULL) + seed++); // seed is static so it will be incremented each time the function is called, so the seed will be different each time
	int random = rand() % 3;
	switch (random)
	{
	case 0:
		std::cout << "Generated A" << std::endl;
		return new A();
	case 1:
		std::cout << "Generated B" << std::endl;
		return new B();
	case 2:
		std::cout << "Generated C" << std::endl;
		return new C();
	default:
		std::cerr << "Error creating object" << std::endl;
		return NULL;
	}
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "The pointer you gave me is of type A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "The pointer you gave me is of type B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "The pointer you gave me is of type C" << std::endl;
}

void identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "The reference you gaven to me is of type A" << std::endl;
	}
	catch (std::bad_cast &e)
	{
	}
	try
	{
		B &b = dynamic_cast<B &>(p);
		(void)b;
		std::cout << "The reference you gaven to me is of type B" << std::endl;
	}
	catch (std::bad_cast &e)
	{
	}
	try
	{
		C &c = dynamic_cast<C &>(p);
		(void)c;
		std::cout << "The reference you gaven to me is of type C" << std::endl;
	}
	catch (std::bad_cast &e)
	{
	}
}