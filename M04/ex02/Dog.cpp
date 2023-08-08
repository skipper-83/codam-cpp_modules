#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << GRAY"Dog standard constructor called"NO_COLOR << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
	return ;
}

Dog::~Dog(void)
{
	std::cout << GRAY"Dog destructor called"NO_COLOR << std::endl;
	delete this->brain;
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

std::string Dog::getIdea(int n) const
{
	return (this->brain->ideas[n]);
}

void Dog::setIdea(int n, std::string idea)
{
	this->brain->ideas[n] = idea;
	return ;
}

void Dog::brainDump(void)
{
	this->brain->dump();
}

