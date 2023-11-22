#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << GRAY << "Cat standard constructor called" << NO_COLOR << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
	return ;
}

Cat::~Cat(void)
{
	std::cout << GRAY << "Cat destructor called" << NO_COLOR << std::endl;
	delete this->brain;
	return ;
}

Cat::Cat(Cat const& src)
{
	std::cout << GRAY << "Cat copy constructor called" << NO_COLOR << std::endl;
	*this = src;
	return ;
}

Cat& Cat::operator=(Cat const& src)
{
	std::cout << GRAY << "Cat assignment operator called" << NO_COLOR << std::endl;
	this->type = src.type;
	this->brain = new Brain(*(src.brain));
	return (*this);
}

void Cat::makeSound(void) const
{
	std::cout <<"Meoowwww" << std::endl;
	return ;
}

std::string Cat::getIdea(int n) const
{
	return (this->brain->ideas[n]);
}

void Cat::setIdea(int n, std::string idea)
{
	this->brain->ideas[n] = idea;
	return ;
}

void Cat::brainDump(void)
{
	this->brain->dump();
}