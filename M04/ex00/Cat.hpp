#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat(void);
		~Cat(void);
		Cat(Cat const& src);

		Cat&			operator=(Cat const& src);
		virtual void	makeSound(void) const;
};

#endif