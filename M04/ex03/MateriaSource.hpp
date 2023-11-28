#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	public:
						MateriaSource(void);
						MateriaSource(const MateriaSource& src);
						~MateriaSource(void);

		MateriaSource&	operator=(const MateriaSource& rhs);
		void			learnMateria(AMateria* src);
		AMateria*		createMateria(const std::string& type);
		void			print_knowledge();

	private:
		AMateria*		_knowledge[4];
};

#endif