#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	this->_health = 100;
	this->_energy = 100;
	this->_attack_damage = 30;
	std::cout << GRAY"FragTrap standard constructor called"NO_COLOR << std::endl;
	return ;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << GRAY"FragTrap string constructor called"NO_COLOR << std::endl;
	this->_health = 100;
	this->_energy = 100;
	this->_attack_damage = 30;
	return ;
}

FragTrap::FragTrap(FragTrap const& src) : ClapTrap(src)
{
	std::cout << GRAY"FragTrap copy constructor called"NO_COLOR << std::endl;
}

FragTrap& FragTrap::operator=(FragTrap const& src)
{

	std::cout << GRAY"FragTrap assignment operator called"NO_COLOR << std::endl;
	this->_name = src._name;
	this->_health = src._health;
	this->_attack_damage = src._attack_damage;
	this->_energy = src._energy;
	return(*this);
}

FragTrap::~FragTrap()
{
	std::cout << GRAY"FragTrap destructor called"NO_COLOR << std::endl;
	return ;
}

void	FragTrap::attack(std::string const& target)
{
	if (this->_energy)
	{
		std::cout << "FragTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
		--(this->_energy);
	}
	else
		std::cout << "FragTrap " << this->_name << " has no energy left and cannot attack" << std::endl;
	return ;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->_name << " is eagerly looking around for high fives" << std::endl;
}

// std::ostream&	operator<<(std::ostream& os, FragTrap const& t)
// {
// 	os << "FragTrap " << t.getName() << " has " << t.getHealth() << " hitpoints and " << t.getEnergy() << " energy. His attack gives " << t.getDamage() << " damage.";
// 	return (os);
// }
