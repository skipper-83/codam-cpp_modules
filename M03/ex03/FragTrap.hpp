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

		protected:
			// std::string		 	_name;
			unsigned int		_health;
			unsigned int		_energy;
			unsigned int		_attack_damage;
};

// std::ostream&	operator<<(std::ostream& os, FragTrap const& t);

#endif