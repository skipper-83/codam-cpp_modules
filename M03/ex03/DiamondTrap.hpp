#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		
		virtual ~DiamondTrap();

		DiamondTrap& operator=(DiamondTrap const& src);

		void	whoAmI(void);
		void	attack(std::string name);

	private:
		std::string _name;
};

#endif