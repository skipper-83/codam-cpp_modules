#include "Ice.hpp"

void	leaks_f(void)
{
	system ("leaks -q materia");
}

int main(void)
{
	std::cout << std::endl << "ICE CONSTRUCTOR TESTS" << std::endl;
	AMateria *cornetto = new Ice();
	AMateria *magnum = new Ice(*((Ice *)cornetto));
	Ice copy;

	std::cout << "cornetto: " << cornetto->getType() << std::endl;
	AMateria *aldi_cornetto = cornetto->clone();
	std::cout << "aldi cornetto: " << aldi_cornetto->getType() << std::endl;
	std::cout << "magnum: "  << magnum->getType() << std::endl;
	copy = *((Ice *)magnum);
	std::cout << "assigned copy: "  << copy.getType() << std::endl;
	// copy.use(nullptr);
	delete cornetto;
	delete aldi_cornetto;
	delete magnum;
	std::cout << std::endl << std::endl;
	atexit(leaks_f);
}