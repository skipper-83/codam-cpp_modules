#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	std::cout << GRAY << "WrongCat standard constructor called" << NO_COLOR << std::endl;
	this->type = "WrongCat";
	return ;
}

WrongCat::~WrongCat(void)
{
	std::cout << GRAY << "WrongCat destructor called" << NO_COLOR << std::endl;
	return ;
}

WrongCat::WrongCat(WrongCat const& src)
{
	std::cout << GRAY << "WrongCat copy constructor called" << NO_COLOR << std::endl;
	this->type = src.type;
	return ;
}

WrongCat& WrongCat::operator=(WrongCat const& src)
{
	std::cout << GRAY << "WrongCat assignment operator called" << NO_COLOR << std::endl;
	this->type = src.type;
	return (*this);
}

void WrongCat::makeSound(void) const
{
	std::cout <<"WrongMeoowwww" << std::endl;
	return ;
}
