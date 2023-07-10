#include <iostream>
#include "Zombie.hpp"

int	main()
{
	Zombie	*horde;

	horde = zombieHorde(10, "jan");
	horde->announce();			// is indeed a pointer to the first zombie
	for(int i = 1; i < 10; i++)
		horde[i].announce();
	delete [] horde;
}