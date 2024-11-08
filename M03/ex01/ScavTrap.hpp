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

	// *** To allow values of parent class to differentiaie fromt the gandparent in diamond inheritance, uncomment the following lines *** //
	// protected:
	// 	unsigned int		_energy;
	// 	unsigned int		_attack_damage;
};


#endif