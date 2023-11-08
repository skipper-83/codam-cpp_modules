#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("generic claptrap"), _health(10), _energy(10), _attack_damage(0)
{
	std::cout << GRAY << "Standard constructor called" << NO_COLOR << std::endl;
	return ;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _health(10), _energy(10), _attack_damage(0)
{
	std::cout << GRAY << "String constructor called" << NO_COLOR << std::endl;
	return ;
}

ClapTrap::ClapTrap(ClapTrap const& src) : _name(src._name), _energy(src._energy), _attack_damage(src._attack_damage), _health(src._health)
{
	std::cout << GRAY << "Copy constructor called" << NO_COLOR << std::endl;
	return ;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << GRAY << "Destructor called" << NO_COLOR << std::endl;
	return ;
}

ClapTrap&	ClapTrap::operator=(ClapTrap const& src)
{
	this->_name = src._name;
	this->_attack_damage = src._attack_damage;
	this->_energy = src._energy;
	this->_health = src._health;
	std::cout << GRAY << "Assigment constructor called" << NO_COLOR << std::endl;
	return (*this);
}

void ClapTrap::attack(std::string const &target)
{
	if (this->_energy && this->_health)
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
		--(this->_energy);
	}
	else if (!this->_health)
		std::cout << "ClapTrap " << this->_name << " is dead and therefore incapable of doing anything" << std::endl;
	else
		std::cout << "ClapTrap " << this->_name << " has no energy left and cannot attack" << std::endl;
	return ;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_health > amount && this->_health)
	{
		this->_health -= amount;
		std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage and has " << this->_health << " left" << std::endl;
	}
	else if (!this->_health)
		std::cout << "ClapTrap " << this->_name << " is dead and can take no more damage" << std::endl;
	else
	{
		std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage and has died" << std::endl;
		this->_health = 0;
	}
	return ;

}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energy && this->_health)
	{
		this->_health += amount;
		std::cout << "ClapTrap " << this->_name << " is healed for " << amount << " and now has " << this->_health << " points of health" << std::endl;
	}
	else if (!this->_health)
		std::cout << "ClapTrap " << this->_name << " is dead and cannot be healed" << std::endl;
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