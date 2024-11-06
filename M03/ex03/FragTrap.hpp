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

	protected: // the only way to have differentiating values between the children of ClapTrap is to give them their own attributes
		unsigned int		_energy; 
		unsigned int		_attack_damage;
};

#endif