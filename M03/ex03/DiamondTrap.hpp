#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"
# define EXTRA "\e[38;5;200m"

class DiamondTrap : public ScavTrap, public FragTrap
{
	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		
		virtual ~DiamondTrap();

		DiamondTrap& operator=(DiamondTrap const& src);

		void	whoAmI(void);
		using	ScavTrap::attack;
		using	ScavTrap::_energy;


	protected:
		unsigned int		_health;
		unsigned int		_attack_damage;

	private:
		std::string _name;
};

// std::ostream&	operator<<(std::ostream& os, DiamondTrap const& t);

#endif