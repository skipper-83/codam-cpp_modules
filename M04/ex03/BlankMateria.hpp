#ifndef BlankMateria_HPP
# define BlankMateria_HPP
# include "AMateria.hpp"

class BlankMateria : public AMateria
{
	public:
						BlankMateria(void);
						BlankMateria(std::string type);
						BlankMateria(BlankMateria const& src);
		BlankMateria&	operator=(BlankMateria const& src);
						~BlankMateria(void);

		AMateria*		clone(void) const;
		void			use(ICharacter& target);
};
#endif