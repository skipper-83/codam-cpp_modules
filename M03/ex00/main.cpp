#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	one("piet");
	ClapTrap	two("klaas");

	one.attack("klaas");
	two.takeDamage(2);

}