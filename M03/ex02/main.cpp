// #include "ClapTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	FragTrap fragger("fragger");
	FragTrap frobot(fragger);
	FragTrap fragcop;

	frobot.takeDamage(20);
	fragcop.beRepaired(10);
	fragcop.attack("the void");
	std::cout << fragger << std::endl << frobot << std::endl << fragcop << std::endl;
	fragcop = fragger;
	std::cout << fragcop << std::endl;

	fragger.attack("fries");
	std::cout << frobot << std::endl;
	frobot.attack("enemies");
	std::cout << fragcop << std::endl;
	for(int i=0; i < 100; i++)
		fragger.attack("the enemies in his head");
	std::cout << fragger << std::endl;
	fragger.highFivesGuys();
	fragger.takeDamage(101);
	frobot.highFivesGuys();
	frobot.beRepaired(50);
	frobot.takeDamage(131);
	frobot.beRepaired(1);
	frobot.attack("something");
	frobot.highFivesGuys();
}