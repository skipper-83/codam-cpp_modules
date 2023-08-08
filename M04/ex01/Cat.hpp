#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	public:
		Cat(void);
		~Cat(void);
		Cat(Cat const& src);

		Cat&					operator=(Cat const& src);
		virtual void			makeSound(void) const;
		virtual std::string		getIdea(int n) const;
		virtual void			setIdea(int n, std::string idea);
		virtual void			brainDump(void);

	private:
		Brain*	brain;
};

#endif