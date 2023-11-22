#include "Animal.hpp"

Animal::Animal(void) : type("Generic Animal")
{
	std::cout << GRAY << "Animal standard constructor called" << NO_COLOR << std::endl;
	return ;
}

Animal::~Animal(void)
{
	std::cout << GRAY << "Animal destructor called" << NO_COLOR << std::endl;
	return ;
}

Animal::Animal(Animal const &src)
{
	std::cout << GRAY << "Animal copy constructor called" << NO_COLOR << std::endl;
	this->type = src.getType();
	return ;
}

Animal &Animal::operator=(Animal const &src)
{
	std::cout << GRAY << "Animal assignment operator called" << NO_COLOR << std::endl;
	this->type = src.getType();
	return (*this);
}

void Animal::makeSound(void) const
{
	std::cout << "*** generic animal noise ***" << std::endl;
	return ;
}

std::string Animal::getType(void) const
{
	return std::string(this->type);
}

std::string Animal::getIdea(int n) const
{
	return ("can't get ideas from generic animal");
}

void Animal::setIdea(int n, std::string idea)
{
	std::cout << "Can't set idea to generic animal" << std::endl;
}

void Animal::brainDump(void)
{
	std::cout << "Can't dump brain of generic animal" << std::endl;
}
