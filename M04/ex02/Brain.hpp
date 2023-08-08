#ifndef	BRAIN_HPP
#define BRAIN_HPP

# define GRAY "\e[38;5;243m"
# define NO_COLOR "\e[0m"
# include <iostream>


class Brain
{
	public:
		Brain();
		~Brain();
		Brain(Brain const& src);

		Brain&	operator=(Brain const& src);
		std::string	ideas[100];
		void		dump(void);
};

#endif