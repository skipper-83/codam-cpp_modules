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

		// ScavTrap& operator=(ScavTrap const& src);
		void attack(std::string const& target);
		void guardGate();

	protected:
		// std::string		 	_name;
		// unsigned int		_health;
		unsigned int		_energy;
		unsigned int		_attack_damage;
};

// std::ostream&	operator<<(std::ostream& os, ScavTrap const& t);

#endif