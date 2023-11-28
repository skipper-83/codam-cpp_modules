#include "BlankMateria.hpp"
#include <cctype>

BlankMateria::BlankMateria(void) : AMateria("blankmateria")
{
	std::cout << GRAY << "BlankMateria standard constructor called" << NO_COLOR << std::endl;
	return ;
}

BlankMateria::BlankMateria(std::string type) : AMateria(type)
{
	std::cout << GRAY << "BlankMateria string constructor called" << NO_COLOR << std::endl;
	return ;
}

BlankMateria::BlankMateria(BlankMateria const &src) : AMateria(src)
{
	std::cout << GRAY << "BlankMateria copy constructor called" << NO_COLOR << std::endl;
	return ;
}

BlankMateria &BlankMateria::operator=(BlankMateria const &src)
{
	std::cout << GRAY << "BlankMateria copy assignment operator called" << NO_COLOR << std::endl;
	if (this != &src)
		AMateria::operator=(src);
	return (*this);
}

BlankMateria::~BlankMateria(void)
{
	std::cout << GRAY << "BlankMateria destructor called" << NO_COLOR << std::endl;
	return ;
}

AMateria *BlankMateria::clone() const
{
	BlankMateria	*new_BlankMateria = new BlankMateria(this->_type);
	return (new_BlankMateria);
}

void BlankMateria::use(ICharacter &target)
{
	std::cout << "* uses BlankMateria " << this->_type << " for their own benefit on " << target.getName() << " *" << std::endl;
}
