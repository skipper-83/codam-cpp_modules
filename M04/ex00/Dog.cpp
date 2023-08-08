#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << GRAY"Dog standard constructor called"NO_COLOR << std::endl;
	this->type = "Dog";
	return ;
}

Dog::~Dog(void)
{
	std::cout << GRAY"Dog destructor called"NO_COLOR << std::endl;
	return ;
}

Dog::Dog(Dog const& src)
{
	std::cout << GRAY"Dog copy constructor called"NO_COLOR << std::endl;
	this->type = src.type;
	return ;
}

Dog& Dog::operator=(Dog const& src)
{
	std::cout << GRAY"Dog assignment operator called"NO_COLOR << std::endl;
	this->type = src.type;
	return (*this);
}

void Dog::makeSound(void) const
{
	std::cout <<"Bark. Bark. Bark. Pant. Pant." << std::endl;
	return ;
}
