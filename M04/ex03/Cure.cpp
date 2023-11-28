#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure")
{
	std::cout << GRAY << "Cure standard constructor called" << NO_COLOR << std::endl;
	return ;
}

Cure::Cure(Cure const &src) : AMateria(src)
{
	std::cout << GRAY << "Cure copy constructor called" << NO_COLOR << std::endl;
	return ;
}

Cure &Cure::operator=(Cure const &src)
{
	std::cout << GRAY << "Cure copy assignment operator called" << NO_COLOR << std::endl;
	if (this != &src)
		AMateria::operator=(src);
	return (*this);
}

Cure::~Cure(void)
{
	std::cout << GRAY << "Cure destructor called" << NO_COLOR << std::endl;
	return ;
}

AMateria *Cure::clone() const
{
	Cure	*new_Cure = new Cure();
	return (new_Cure);
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
