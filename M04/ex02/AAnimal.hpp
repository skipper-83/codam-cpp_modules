#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# define GRAY "\e[38;5;243m"
# define NO_COLOR "\e[0m"
# include <iostream>

class AAnimal
{
	public:
		AAnimal(void);
		virtual	~AAnimal(void);
		AAnimal(AAnimal const& src);

		AAnimal&			operator=(AAnimal const& src);
		virtual void	makeSound(void) const = 0;
		std::string		getType(void) const;
		virtual std::string		getIdea(int n) const = 0;
		virtual void			setIdea(int n, std:: string idea) = 0;
		virtual void			brainDump(void) = 0;

	protected:
		std::string	type;

};

#endif