#include <iostream>
#include "Zombie.hpp"

int	main()
{
	Zombie	*pZombie;

	pZombie = newZombie("klaas");
	pZombie->announce();
	randomChump("piet");
	delete pZombie;
}