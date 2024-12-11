#include "whatever.hpp"

#include <iostream>

int main(void)
{
	int a = 2;
	int b = 3;

	swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << min(a, b) << std::endl;
	std::cout << "max(a, b) = " << max(a, b) << std::endl;

	std::string c = "string1";
	std::string d = "string2";

	swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min(c, d) = " << min(c, d) << std::endl;
	std::cout << "max(c, d) = " << max(c, d) << std::endl;

	float e = 1.1f;
	float f = 1.2f;

	swap(e, f);
	std::cout << "e = " << e << ", f = " << f << std::endl;
	std::cout << "min(e, f) = " << min(e, f) << std::endl;
	std::cout << "max(e, f) = " << max(e, f) << std::endl;
	e -= 0.1f;
	std::cout << "e address = " << &e << ", f address = " << &f << std::endl;
	std::cout << "e = " << e << ", f = " << f << std::endl;
	std::cout << "min(e, f) = " << min(e, f) << " address = " << &min(e, f) << std::endl;
	std::cout << "max(e, f) = " << max(e, f) << " address = " << &max(e, f) << std::endl;

	return 0;
}