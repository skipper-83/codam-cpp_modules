#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(FragTrap const& src);
		~FragTrap();

		FragTrap& operator=(FragTrap const& src);
		void attack(std::string const& target);
		void highFivesGuys(void);
};

// std::ostream&	operator<<(std::ostream& os, FragTrap const& t);

#endif