#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# define GRAY "\e[38;5;243m"
# define NO_COLOR "\e[0m"
# include <iostream>

class ClapTrap
{
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const& src);
		~ClapTrap(void);

		ClapTrap&	operator=(ClapTrap const& src);

		void		attack(std::string const& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);

	
		std::string		getName(void) const;
		unsigned int	getHealth(void) const;
		unsigned int	getEnergy(void) const;
		unsigned int	getDamage(void) const;

	protected:
		std::string		 	_name;
		unsigned int		_health;
		unsigned int		_energy;
		unsigned int		_attack_damage;

};

std::ostream&	operator<<(std::ostream& os, ClapTrap const& t);

#endif