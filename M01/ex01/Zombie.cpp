#include <iostream>
#include "Zombie.hpp"

void	Zombie::announce()
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ...\n";
}

Zombie::Zombie()
{
	std::cout << GRAY << "Generic zombie made" << NO_COLOR << std::endl;
}

Zombie::Zombie(std::string new_name)
{
	_name = new_name;
	std::cout << GRAY << "Zombie" << this->_name <<" made" << NO_COLOR;
}

Zombie::~Zombie()
{
	std::cout << GRAY << "Zombie destroyed" << NO_COLOR << std::endl;	
	return;
}

void	Zombie::setName(std::string name)
{
	_name = name;
}


