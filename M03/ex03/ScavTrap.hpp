#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const& src);
		~ScavTrap();

		ScavTrap& operator=(ScavTrap const& src);
		void attack(std::string const& target);
		void guardGate();

	protected: // the only way to have differentiating values between the children of ClapTrap is to give them their own attributes
		unsigned int		_energy;
		unsigned int		_attack_damage;

};


#endif