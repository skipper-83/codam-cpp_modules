#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap airfryer("airfryer");
	ScavTrap robot(airfryer);
	ScavTrap copy;

	std::cout << "ScavTrap " << airfryer.getName() << " has " << airfryer.getHealth() << " health points" << std::endl;
	std::cout << "ScavTrap " << airfryer.getName() << " has " << airfryer.getEnergy() << " energy points" << std::endl;
	std::cout << "ScavTrap " << airfryer.getName() << " has " << airfryer.getDamage() << " attack points" << std::endl;
	std::cout << "\n\n";

	robot.takeDamage(20);
	copy.beRepaired(10);
	std::cout << airfryer << std::endl << robot << std::endl << copy << std::endl;
	copy = airfryer;
	std::cout << copy << std::endl;

	airfryer.attack("fries");
	std::cout << robot << std::endl;
	robot.attack("enemies");
	std::cout << copy << std::endl;
	for(int i=0; i < 51; i++)
		airfryer.attack("the enemies in his head");
	std::cout << airfryer << std::endl;
	airfryer.takeDamage(99);
	airfryer.guardGate();
	robot.guardGate();
	robot.beRepaired(50);
	robot.takeDamage(131);
	robot.beRepaired(1);
	robot.attack("something");
	robot.guardGate();
}