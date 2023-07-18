#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("generic ClapTrap"), _health(0), _energy(0), _attack_damage(0)
{
	std::cout << GRAY"ClapTrap standard constructor called"NO_COLOR << std::endl;
	return ;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _health(10), _energy(10), _attack_damage(0)
{
	std::cout << GRAY"ClapTrap string constructor called"NO_COLOR << std::endl;
	return ;
}

ClapTrap::ClapTrap(ClapTrap const& src) : _name(src._name), _energy(src._energy), _attack_damage(src._attack_damage), _health(src._health)
{
	std::cout << GRAY"ClapTrap copy constructor called"NO_COLOR << std::endl;
	return ;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << GRAY"ClapTrap destructor called"NO_COLOR << std::endl;
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
		std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage and has " << this->_health << " left" << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage and has died" << std::endl;
		this->_health = 0;
	}
	return ;

}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energy)
	{
		this->_health += amount;
		std::cout << "ClapTrap " << this->_name << " is healed for " << amount << " and now has " << this->_health << " points of health" << std::endl;
	}
	else
		std::cout << "ClapTrap " << this->_name << " has no energy left and cannot be repaired" << std::endl;
}

std::string ClapTrap::getName(void) const
{
	return (this->_name);
}

unsigned int ClapTrap::getHealth(void) const
{
	return (this->_health);
}

unsigned int ClapTrap::getEnergy(void) const
{
	return (this->_energy);
}

unsigned int ClapTrap::getDamage(void) const
{
	return (this->_attack_damage);
}

std::ostream&	operator<<(std::ostream& os, ClapTrap const& t)
{
	os << "ClapTrap " << t.getName() << " has " << t.getHealth() << " hitpoints and " << t.getEnergy() << " energy. His attack gives " << t.getDamage() << " damage.";
	return (os);
}