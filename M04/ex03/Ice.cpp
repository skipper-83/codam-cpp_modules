#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice")
{
	std::cout << GRAY"Ice standard constructor called"NO_COLOR << std::endl;
	return ;
}

Ice::Ice(Ice const &src) : AMateria(src)
{
	std::cout << GRAY"Ice copy constructor called"NO_COLOR << std::endl;
	return ;
}

Ice &Ice::operator=(Ice const &src)
{
	std::cout << GRAY"Ice copy assignment operator called"NO_COLOR << std::endl;
	if (this != &src)
		AMateria::operator=(src);
	return (*this);
}

Ice::~Ice(void)
{
	std::cout << GRAY"Ice destructor called"NO_COLOR << std::endl;
	return ;
}

AMateria *Ice::clone() const
{
	Ice	*new_ice = new Ice();
	return (new_ice);
}
