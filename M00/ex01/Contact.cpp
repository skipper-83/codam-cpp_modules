#include "Contact.hpp"

Contact::Contact(std::string fname, std::string lname, std::string nickname, std::string number, std::string secret, int index) : \
	_first_name (fname), _last_name(lname), _nick_name(nickname), _phone_number(number), _dark_secret(secret), _index(index)
{
	std::cout << GRAY << "Contact created" << NO_COLOR << std::endl;
	return;
}

Contact::~Contact()
{
	std::cout << GRAY << "Contact deleted" << NO_COLOR << std::endl;
	return;
}

void	Contact::displayAsListItem()
{
	std::cout << '|';
	std::cout <<  std::setw(10) << _index;
	std::cout << '|';
	std::cout << std::setw(10) << this->_truncateItem(_first_name);
	std::cout << '|';
	std::cout << std::setw(10) << this->_truncateItem(_last_name);
	std::cout << '|';
	std::cout << std::setw(10) << this->_truncateItem(_nick_name);
	std::cout << '|';
	std::cout << std::endl;
}

void	Contact::displayFullContact()
{
	std::cout << BOLD << "Contact Printout" << NO_COLOR << std::endl;
	std::cout << "First Name:\t" << this->_first_name << std::endl;
	std::cout << "Last Name:\t" << this->_last_name << std::endl;
	std::cout << "Nickname:\t" << this->_nick_name << std::endl;
	std::cout << "Phone #:\t" << this->_phone_number << std::endl;
	std::cout << "Dark Secret:\t" << this->_dark_secret << std::endl;
}

std::string	Contact::_truncateItem(std::string str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + '.');
	else
		return (str);
}