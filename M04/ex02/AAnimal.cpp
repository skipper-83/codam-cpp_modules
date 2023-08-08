#include "AAnimal.hpp"

AAnimal::AAnimal(void) : type("Generic AAnimal")
{
	std::cout << GRAY"AAnimal standard constructor called"NO_COLOR << std::endl;
	return ;
}

AAnimal::~AAnimal(void)
{
	std::cout << GRAY"AAnimal destructor called"NO_COLOR << std::endl;
	return ;
}

AAnimal::AAnimal(AAnimal const &src)
{
	std::cout << GRAY"AAnimal copy constructor called"NO_COLOR << std::endl;
	this->type = src.getType();
	return ;
}

AAnimal &AAnimal::operator=(AAnimal const &src)
{
	std::cout << GRAY"AAnimal assignment operator called"NO_COLOR << std::endl;
	this->type = src.getType();
	return (*this);
}

std::string AAnimal::getType(void) const
{
	return std::string(this->type);
}