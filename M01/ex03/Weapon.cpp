#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->_type = type;
	return;
}

Weapon::~Weapon()
{
	return;
}

void	Weapon::setType(std::string new_type)
{
	this->_type = new_type;
	return;
}

std::string const&	Weapon::getType(void) const
{
	return (this->_type);
}