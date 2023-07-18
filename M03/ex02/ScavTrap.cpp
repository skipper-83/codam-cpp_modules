#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << GRAY"ScavTrap standard constructor called"NO_COLOR << std::endl;
	return ;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << GRAY"ScavTrap string constructor called"NO_COLOR << std::endl;
	this->_health = 100;
	this->_energy = 50;
	this->_attack_damage = 20;
	return ;
}

ScavTrap::ScavTrap(ScavTrap const& src) : ClapTrap(src)
{
	std::cout << GRAY"ScavTrap copy constructor called"NO_COLOR << std::endl;
}

ScavTrap& ScavTrap::operator=(ScavTrap const& src)
{

	std::cout << GRAY"ScavTrap assignment operator called"NO_COLOR << std::endl;
	this->_name = src._name;
	this->_health = src._health;
	this->_attack_damage = src._attack_damage;
	this->_energy = src._energy;
	return(*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << GRAY"ScavTrap destructor called"NO_COLOR << std::endl;
	return ;
}

void	ScavTrap::attack(std::string const& target)
{
	if (this->_energy)
	{
		std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
		--(this->_energy);
	}
	else
		std::cout << "ScavTrap " << this->_name << " has no energy left and cannot attack" << std::endl;
	return ;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->_name << " is in guard mode" << std::endl;
}

// std::ostream&	operator<<(std::ostream& os, ScavTrap const& t)
// {
// 	os << "ScavTrap " << t.getName() << " has " << t.getHealth() << " hitpoints and " << t.getEnergy() << " energy. His attack gives " << t.getDamage() << " damage.";
// 	return (os);
// }
