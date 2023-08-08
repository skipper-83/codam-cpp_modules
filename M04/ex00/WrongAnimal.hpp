#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

# define GRAY "\e[38;5;243m"
# define NO_COLOR "\e[0m"
# include <iostream>

class WrongAnimal
{
	public:
		WrongAnimal(void);
		virtual	~WrongAnimal(void);
		WrongAnimal(WrongAnimal const& src);

		WrongAnimal&			operator=(WrongAnimal const& src);
		void					makeSound(void) const;
		std::string				getType(void) const;

	protected:
		std::string	type;
};

#endif