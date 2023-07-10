#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->_idx = 0;
	bzero(this->_contacts, sizeof(Contact *) * ENTRIES);
	std::cout << GRAY << "Phonebook made" << NO_COLOR << std::endl;
	return;
}

PhoneBook::~PhoneBook()
{
	for (size_t i = 0; i < ENTRIES; i++)
		if (this->_contacts[i] != NULL)
			delete this->_contacts[i];
	std::cout << GRAY << "Phonebook deleted" << NO_COLOR << std::endl;
	return;
}

void	PhoneBook::addContact()
{
	Contact	*new_contact;
	std::string fname;
	std::string	lname;
	std::string	nname;
	std::string number;
	std::string secret;

	fname = this->_getInput("First name: ");
	lname = this->_getInput("Last name: ");
	nname = this->_getInput("Nickname: ");
	number = this->_getInput("Phone number: ");
	secret = this->_getInput("Your dark secret: ");
	std::cout << std::endl;
	if (_contacts[_idx] != NULL)
	{
		std::cout << "Deleting oldest contact... ";
		delete _contacts[_idx];
	}
	std::cout << "Creating new contact... ";
	new_contact = new Contact(fname, lname, nname, number, secret, _idx);
	this->_contacts[_idx] = new_contact;
	this->_idx < ENTRIES - 1 ? this->_idx++ : this->_idx = 0;
	std::cout << "Contact added to phonebook" << std::endl;
	return;
}

void	PhoneBook::searchContact()
{
	int		index;

	if (this->_contacts[0] == NULL)
	{
		std::cout << "No contacts in book. Please add a contact before searching for one" << std::endl;
		return;
	}
	index = 0;
	this->_showList();
	while (1)
	{	
		std::cout << "Please provide the index # of the contact you want me to show: ";
		if (std::cin >> index)
			break ;
		else
		{
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "Please enter a valid number" << std::endl;
		}
	}
	std::cin.ignore();
	if (index > ENTRIES - 1 || index < 0 || this->_contacts[index] == NULL)
	{
		std::cout << "Index out of range. Returning to main menu." << std::endl;
		return;
	}
	std::cout << std::endl;
	this->_contacts[index]->displayFullContact();
	std::cout << std::endl;
	return;

}

void	PhoneBook::_showList()
{
	std::cout << " ___________________________________________" << std::endl;
	std::cout << BLUE_BG << '|';
	std::cout <<  std::setw(10) << "index";
	std::cout << '|';
	std::cout << std::setw(10) << "1st name";
	std::cout << '|';
	std::cout << std::setw(10) << "last name";
	std::cout << '|';
	std::cout << std::setw(10) << "nickname";
	std::cout << '|';
	std::cout << NO_COLOR << std::endl;
	std::cout << BLUE_BG  << "|__________|__________|__________|__________|" << NO_COLOR << std::endl;
	for (int i = 0; i < ENTRIES; i++)
	{
		if (this->_contacts[i] != NULL)
			this->_contacts[i]->displayAsListItem();
	}
	std::cout << std::endl;
	return;
}

std::string	PhoneBook::_getInput(std::string prompt)
{
	std::string	result;

	while (1)
	{
		std::cout << prompt;
		std::getline(std::cin, result);
		if (result.length() > 0)
			break ;
		std::cout << "I'm sorry, but I do require an input." << std::endl;
	}
	return (result);
}