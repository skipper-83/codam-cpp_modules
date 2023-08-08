#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	one("piet");
	ClapTrap	two("klaas");
	ClapTrap	three(two);
	ClapTrap	four;

	std::cout << "*** INITIALIZATIONS ***" << std::endl;
	std::cout << one << std::endl << two << std::endl << three << std::endl << four << std::endl;
	four = three;
	std::cout << four << std::endl << std::endl;	

	std::cout << "*** MEMBER FUNCTIONS ***" << std::endl;
	one.attack("klaas");
	two.takeDamage(2);

	std::cout << one << std::endl;
	one.takeDamage(9);
	two.takeDamage(8);
	one.beRepaired(2);
	for(int i=0; i < 10; i++)
		one.attack("the enemies in his head");
	std::cout << one << std::endl;
	one.beRepaired(7);
	two.beRepaired(1);
	two.attack("someone");
	two.takeDamage(1);
}