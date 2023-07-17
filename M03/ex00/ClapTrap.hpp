#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# define GRAY "\e[38;5;243m"
# define NO_COLOR "\e[0m"
# include <iostream>

class ClapTrap
{
	public:
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const& src);
		~ClapTrap(void);

		ClapTrap&	operator=(ClapTrap const& src);

		void		attack(std::string const& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);


	private:
		ClapTrap(void);
		std::string		 	_name;
		unsigned int		_health;
		unsigned int		_energy;
		unsigned int		_attack_damage;

};

&ostream	operator<<(&ostream os, ClapTrap const& t)
{
	os << "ClapTrap " << t._n
}

#endif