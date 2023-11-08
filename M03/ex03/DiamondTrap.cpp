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
	this->_energy = ScavTrap::_energy;
	std::cout << "FragTrap vaules\n" 
	<< "\tHP: \n" << FragTrap::_health 
	<< "\tAttack: \n" << FragTrap::_attack_damage 
	<< "\tEnergy: \n" << FragTrap::_energy 
	<< "ScavTrap vaules\n" 
	<< "\tHP: \n" << ScavTrap::_health 
	<< "\tAttack: \n" << ScavTrap::_attack_damage 
	<< "\tEnergy: \n" << ScavTrap::_energy 
	<< "DiamondTrap vaules\n"
	<< "\tHP: \n" << this->_health 
	<< "\tAttack: \n" << this->_attack_damage 
	<< "\tEnergy: \n" << this->_energy << std::endl;
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

// void	DiamondTrap::attack(std::string name)
// {
// 	ScavTrap::attack(name);
// }