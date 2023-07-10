#ifndef ZOMBIE_H
# define ZOMBIE_H
# include <iostream>
# define GRAY "\e[38;5;235m"
# define NO_COLOR "\e[0m"

class Zombie
{
	public:
		void		announce(void);
					Zombie(void);
					Zombie(std::string name);
					~Zombie(void);
		void		setName(std::string name);

	private:
		std::string	_name;
};

Zombie	*zombieHorde(int N, std::string name);

#endif