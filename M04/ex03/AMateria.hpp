#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# define GRAY "\e[38;5;243m"
# define NO_COLOR "\e[0m"
# include <iostream>
# include "ICharacter.hpp"

class AMateria
{
    public:
							AMateria(void);
							AMateria(std::string const & type);
							AMateria(AMateria const& src);
		AMateria			&operator=(AMateria const& src);
		virtual				~AMateria(void);

		std::string const&	getType() const; //Returns the materia type
	
		virtual AMateria*	clone() const = 0;
		virtual void		use(ICharacter& target);

	protected:
        std::string			_type;

};

extern void	**items_on_floor;

#endif