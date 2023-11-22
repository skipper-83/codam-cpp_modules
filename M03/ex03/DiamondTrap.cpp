#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ScavTrap(), FragTrap(), ClapTrap()
{
	this->_name = "generic_Diamondtrap";
	ClapTrap::_name = this->_name + "_clap_name";
}

DiamondTrap::DiamondTrap(std::string name) : ScavTrap(name), FragTrap(name), ClapTrap(name + "_clap_name")
{
	this->_name = name;
	this->_health = FragTrap::_health;
	this->_attack_damage = FragTrap::_attack_damage;
	// this->_energy = ScavTrap::_energy;	
	std::cout << "FragTrap values\n" 
	<< "\tHP: " << FragTrap::_health 
	<< "\n\tAttack: " << FragTrap::_attack_damage 
	<< "\n\tEnergy: " << FragTrap::_energy 
	<< "\nScavTrap values\n" 
	<< "\tHP: " << ScavTrap::_health 
	<< "\n\tAttack: " << ScavTrap::_attack_damage 
	<< "\n\tEnergy: " << ScavTrap::_energy 
	<< "\nDiamondTrap values\n"
	<< "\tHP: " << this->_health 
	<< "\n\tAttack: " << this->_attack_damage 
	<< "\n\tEnergy: " << this->_energy << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << GRAY << "DiamondTrap destructor called" << NO_COLOR << std::endl;
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap const& src)
{

	std::cout << GRAY << "DiamondTrap assignment operator called" << NO_COLOR << std::endl;
	this->_name = src._name;
	ClapTrap::_name = src.ClapTrap::_name;
	this->_health = src._health;
	this->_attack_damage = src._attack_damage;
	this->_energy = src._energy;
	return(*this);
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "I am a ClapTrap named " << this->ClapTrap::_name << " my DiamondTrap name is " << this->_name << std::endl;
}

// std::string DiamondTrap::getName(void) const
// {
// 	return (this->_name);
// }


// std::ostream&	operator<<(std::ostream& os, DiamondTrap const& t)
// {
// 	os << "DiamondTrap " << t.getName() << " has " << t.getHealth() << " hitpoints and " << t.getEnergy() << " energy. His attack gives " << t.getDamage() << " damage.";
// 	return (os);
// }