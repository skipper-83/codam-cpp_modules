#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP
# include "Weapon.hpp"

class HumanB
{
	public:
							HumanB(std::string name);
							~HumanB();
		void				attack(void) const;
		void				setWeapon(Weapon& weapon);

	private:
		Weapon*				_weapon;
		std::string	const	_name;
};

#endif