#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal
{
	public:
		Dog(void);
		~Dog(void);
		Dog(Dog const& src);

		Dog&					operator=(Dog const& src);
		virtual void			makeSound(void) const;
		virtual std::string		getIdea(int n) const;
		virtual void			setIdea(int n, std::string idea);
		virtual void			brainDump(void);

	private:
		Brain	*brain;
};

#endif