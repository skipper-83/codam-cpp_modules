#include <map>
#include <iostream>

int main(void) {
	std::map<std::string, std::string> request;
	std::string input;

	while (true)
	{
		std::cin >> input;
		if (input == "break")
			break ;
		std::cout << input << "\n";
	}
}