#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon)
{
}

HumanA::~HumanA()
{
}

void	HumanA::attack() const
{
	if (this->_weapon.getType() != "")
		std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
	else
		std::cout << this->_name << " is unarmed" << std::endl;
}