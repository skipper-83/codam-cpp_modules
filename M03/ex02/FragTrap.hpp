#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(FragTrap const& src);
		~FragTrap();

		FragTrap& operator=(FragTrap const& src);
		void attack(std::string const& target);
		void highFivesGuys(void);

	// *** To allow values of parent class to differentiaie fromt the gandparent in diamond inheritance, uncomment the following lines *** //
	// protected:
	// 	unsigned int		_energy;
	// 	unsigned int		_attack_damage;
	
};

#endif