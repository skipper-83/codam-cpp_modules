#include "Brain.hpp"

Brain::Brain()
{
	std::cout << GRAY"Brain standard constructor called"NO_COLOR << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "idea " + std::to_string(i);
	return ;
}

Brain::~Brain()
{
	std::cout << GRAY"Brain destructor called"NO_COLOR << std::endl;
	return ;
}

Brain::Brain(Brain const &src)
{
	std::cout << GRAY"Brain copy constructor called"NO_COLOR << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = src.ideas[i];
	return ;
}

void Brain::dump(void)
{
	for(int i = 0; i < 100; i++)
		std::cout << " - " << this->ideas[i] << std::endl;
}
