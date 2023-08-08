#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("Generic WrongAnimal")
{
	std::cout << GRAY"WrongAnimal standard constructor called"NO_COLOR << std::endl;
	return ;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << GRAY"WrongAnimal destructor called"NO_COLOR << std::endl;
	return ;
}

WrongAnimal::WrongAnimal(WrongAnimal const &src)
{
	std::cout << GRAY"WrongAnimal copy constructor called"NO_COLOR << std::endl;
	this->type = src.getType();
	return ;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &src)
{
	std::cout << GRAY"WrongAnimal assignment operator called"NO_COLOR << std::endl;
	this->type = src.getType();
	return (*this);
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "*** generic wrong animal noise ***" << std::endl;
	return ;
}

std::string WrongAnimal::getType(void) const
{
	return std::string(this->type);
}
