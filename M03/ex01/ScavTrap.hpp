#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "../ex00/ClapTrap.hpp"

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

	public:
		using ClapTrap::_health;
};

// std::ostream&	operator<<(std::ostream& os, ScavTrap const& t);

#endif