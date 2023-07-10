#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

void	leaks_f()
{
	system ("leaks -q violence");
}

int main(void)
{
	// atexit(leaks_f);
	{
		Weapon	club = Weapon("crude spiked club");

		HumanA bob = HumanA("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon	club = Weapon("crude spiked club");

		HumanB jim("Jim");
		jim.attack();
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
}