#include <iostream>
#include "Zombie.hpp"

void Zombie::announce()
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ...\n";
	return;
}

Zombie::Zombie(std::string new_name)
{
	this->_name = new_name;
	std::cout << GRAY << "Zombie made" << NO_COLOR << std::endl;
	return;
}

Zombie::~Zombie()
{
	std::cout << GRAY << "Zombie destroyed" << NO_COLOR << std::endl;	
	return;
}