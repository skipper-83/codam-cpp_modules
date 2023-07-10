#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>
# define GRAY "\e[38;5;235m"
# define NO_COLOR "\e[0m"

class Zombie
{
	public:
		void		announce(void);
					Zombie(std::string name);
					~Zombie(void);

	private:
		std::string	_name;
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);
#endif