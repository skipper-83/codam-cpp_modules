// #include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap airfryer("airfryer");
	ScavTrap robot(airfryer);
	ScavTrap copy;

	robot.takeDamage(20);
	copy.beRepaired(10);
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
}