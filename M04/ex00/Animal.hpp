#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# define GRAY "\e[38;5;243m"
# define NO_COLOR "\e[0m"
# include <iostream>

class Animal
{
	public:
		Animal(void);
		virtual	~Animal(void);
		Animal(Animal const& src);

		Animal&			operator=(Animal const& src);
		virtual void	makeSound(void) const;
		std::string		getType(void) const;

	protected:
		std::string	type;
};

#endif