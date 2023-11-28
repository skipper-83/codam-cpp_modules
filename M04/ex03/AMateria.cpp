#include "AMateria.hpp"

AMateria::AMateria(void)
{
	std::cout << GRAY << "AMateria standard constructor called" << NO_COLOR << std::endl;
	this->_type = "generic Materia";
	return ;
}

AMateria::AMateria(std::string const &type)
{
	std::cout << GRAY << "AMateria string constructor called" << NO_COLOR << std::endl;
	this->_type = type;
	return ;
}

AMateria::AMateria(AMateria const &src)
{
	std::cout << GRAY << "AMateria copy constructor called" << NO_COLOR << std::endl;
	if (this != &src)
		this->_type = src._type;
	return ;
}

AMateria &AMateria::operator=(AMateria const &src)
{
	std::cout << GRAY << "AMateria copy assignment operator called" << NO_COLOR << std::endl;
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

AMateria::~AMateria(void)
{
	std::cout << GRAY << "AMateria destructor called" << NO_COLOR << std::endl;
	return ;
}

std::string const &AMateria::getType() const
{
	return (this->_type);
}

void AMateria::use(ICharacter &target)
{
	std::cout << "Calling use on abract class is useless. Would have made this a pure abstract function were it not for the subject" << std::endl;
	return ;
}
