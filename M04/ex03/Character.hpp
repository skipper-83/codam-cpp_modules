#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
	public:
							Character(void);
							Character(std::string name);
							Character(Character const& src);
		Character&			operator=(Character const& rhs);

		std::string const&	getName(void) const;
		void				equip(AMateria* m);
		void				unequip(int idx);
		void				use(int idx, ICharacter& target);
	
	private:
		std::string	const	_name;
		AMateria*			_inventory[4];

};