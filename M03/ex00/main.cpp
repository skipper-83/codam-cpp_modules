#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	one("piet");
	ClapTrap	two("klaas");
	ClapTrap	three(two);
	ClapTrap	four;

	std::cout << "*** INITIALIZATIONS ***\n" 
	<< one << two << three << four;
	four = three;
	std::cout << four << std::endl;	

	std::cout << "*** MEMBER FUNCTIONS ***" << std::endl;
	one.attack("klaas");
	two.takeDamage(2);

	std::cout << one;
	one.takeDamage(9);
	two.takeDamage(8);
	one.beRepaired(2);
	for(int i=0; i < 10; i++)
		one.attack("the enemies in his head");
	std::cout << one;
	one.beRepaired(7);
	two.beRepaired(1);
	two.attack("someone");
	two.takeDamage(1);
}