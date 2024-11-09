#include "ScalarConverter.hpp"

#include <iostream>

void runTests();

int main(int ac, char **av)
{
	if (ac == 2)
		ScalarConverter::convert(av[1]);
	else
	{
		std::cout << "Usage: ./scalar [input]\n";
		std::cout << "Example: ./scalar 42\n";
		std::cout << "Running tests...\n";
		runTests();
	}
	return 0;
}

void test(std::string input)
{
	std::cout << "*** Converting: " << input << "\n";
	ScalarConverter::convert(input);
	std::cout << std::endl;
}

void runTests()
{
	std::cout << "************* Chars *************\n";
	test("'a'");
	test("'3'");
	test("'\''");
	test("'\\'");
	test("' '");
	test("'\t'");
	
	std::cout << "\n\n************* Ints *************\n";
	test("0");
    test("7");
    test("-65");
    test("65");
    test("200");
    test("16777217");
    test("2147483647");
    test("-2147483648");

	std::cout << "\n\n************* Floats *************\n";
	    test("nanf");
    test("inff");
    test("-inff");
    test(".1f");
    test(".0f");
    test("65.0f");
    test("-65.0f");
    test("65.1234f");
    test("65.12345f");

	std::cout << "\n\n************* Doubles *************\n";
	test("nan");
    test("inf");
    test("-inf");
    test("0.1");
    test("65.");
    test("21474.83649");
    test("16777217.0");
    test("2147483647.");
    test("2147483648.");
    test("-2147483649.");
    test("1.12345678901234");

	std::cout << "\n\n************* Invalid *************\n";
	test("");
    test("a");
    test("'10'");
    test("f10.0");
    
    test("2147483648");
    test("-2147483649");
    test("1234123412341234123412");
    
    test("f");
    test("10.f0");
    test("12f");
    test("1.1234567890123456f");
    
    test(".0.2");
    test("1.2.");
    test("1.1234567890123456");

}