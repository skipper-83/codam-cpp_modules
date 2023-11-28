#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << GRAY << "Cat standard constructor called" << NO_COLOR << std::endl;
	this->type = "Cat";
	return ;
}

Cat::~Cat(void)
{
	std::cout << GRAY << "Cat destructor called" << NO_COLOR << std::endl;
	return ;
}

Cat::Cat(Cat const& src)
{
	std::cout << GRAY << "Cat copy constructor called" << NO_COLOR << std::endl;
	this->type = src.type;
	return ;
}

Cat& Cat::operator=(Cat const& src)
{
	std::cout << GRAY << "Cat assignment operator called" << NO_COLOR << std::endl;
	this->type = src.type;
	return (*this);
}

void Cat::makeSound(void) const
{
	std::cout <<"Meoowwww" << std::endl;
	return ;
}
