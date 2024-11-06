#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap jewel("koh_i_noor");
	DiamondTrap	fake;
	// ScavTrap test("scavvy");
	// FragTrap frag("fraggy");

	jewel.whoAmI();
	jewel.attack("rubies");
	jewel.takeDamage(5);
	// std::cout << test << std::endl;
	// std::cout << frag << std::endl;
	// std::cout << jewel << std::endl;
	fake.whoAmI();
	fake = jewel;
	fake.whoAmI();
	fake.guardGate();
	fake.highFivesGuys();
	// std::cout << "this should be protected" << fake._energy;
	std::cout << fake.getEnergy();
	std::cout << fake;
}