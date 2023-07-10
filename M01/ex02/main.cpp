#include <iostream>

int	main()
{
	std::string		myString;
	std::string*	stringPTR;
	std::string&	stringREF = myString;

	stringPTR = &myString;
	myString = "HI THIS IS BRAIN";

	std::cout << "myString address " << &myString << "\n";
	std::cout << "stringPTR address " << stringPTR << "\n";
	std::cout << "stringREF address " << &stringREF << "\n\n";

	std::cout << "myString: " << myString << "\n";
	std::cout << "stringPTR value " << *stringPTR << "\n";
	std::cout << "stringREF value " << stringREF << "\n";
}