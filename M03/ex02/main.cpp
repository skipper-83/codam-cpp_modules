// #include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	ScavTrap airfryer("airfryer");
	ScavTrap robot(airfryer);
	ScavTrap copy;

	robot.takeDamage(20);
	copy.beRepaired(10);
	copy.attack("the void");
	std::cout << airfryer << std::endl << robot << std::endl << copy << std::endl;
	copy = airfryer;
	std::cout << copy << std::endl;

	airfryer.attack("fries");
	std::cout << robot << std::endl;
	robot.attack("enemies");
	std::cout << copy << std::endl;
	for(int i=0; i < 10; i++)
		airfryer.attack("the enemies in his head");
	std::cout << airfryer << std::endl;
	airfryer.takeDamage(99);
	robot.guardGate();
	robot.beRepaired(50);

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
	for(int i=0; i < 10; i++)
		fragger.attack("the enemies in his head");
	std::cout << fragger << std::endl;
	fragger.takeDamage(101);
	frobot.highFivesGuys();
	frobot.beRepaired(50);
}