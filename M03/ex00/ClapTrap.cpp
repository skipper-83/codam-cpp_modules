#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	std::cout << GRAY"Standard constructor called"NO_COLOR << std::endl;
	return ;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _health(10), _energy(10), _attack_damage(0)
{
	std::cout << GRAY"String constructor called"NO_COLOR << std::endl;
	return ;
}

ClapTrap::ClapTrap(ClapTrap const& src) : _name(src._name), _energy(src._energy), _attack_damage(src._attack_damage), _health(src._health)
{
	std::cout << GRAY"Copy constructor called"NO_COLOR << std::endl;
	return ;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << GRAY"Destructor called"NO_COLOR << std::endl;
	return ;
}

ClapTrap&	ClapTrap::operator=(ClapTrap const& src)
{
	this->_name = src._name;
	this->_attack_damage = src._attack_damage;
	this->_energy = src._energy;
	this->_health = src._health;
	std::cout << GRAY"Assigment constructor called"NO_COLOR << std::endl;
	return (*this);
}

void ClapTrap::attack(std::string const &target)
{
	if (this->_energy)
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
		--(this->_energy);
		if (!this->_energy)
			std::cout << "ClapTrap " << this->_name << " is out of energy" << std::endl;
		else
			std::cout << "ClapTrap " << this->_name << " has " << this->_energy << " energy left" << std::endl;
	}
	else
		std::cout << "ClapTrap " << this->_name << " has no energy left and cannot attack" << std::endl;
	return ;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_health > amount)
	{
		this->_health -= amount;
		std::cout << "ClapTrap " << this->_name << " takes " << amount << ", of damage and has " << this->_health << " left" << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << this->_name << " takes " << amount << ", of damage and has died" << std::endl;
		this->_health = 0;
	}
	return ;

}

void ClapTrap::beRepaired(unsigned int amount)
{
	this->_health += amount;
	std::cout << "ClapTrap " << this->_name << " is healed for " << amount << " and now has " << this->_health << " points of health" << std::cout;
}
