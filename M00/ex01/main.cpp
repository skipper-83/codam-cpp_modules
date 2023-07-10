#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook my_phonebook;
	std::string	input;

	do
	{
		std::cout << "Your command: ";
		std::getline(std::cin, input);
		if (input == "ADD")
			my_phonebook.addContact();
		else if (input == "SEARCH")
			my_phonebook.searchContact();
		else if (input == "EXIT")
			break;
		else
		{
			std::cout << std::endl << "Usage: ADD, SEARCH or EXIT" << std::endl;
		}

	}
	while (1);
}