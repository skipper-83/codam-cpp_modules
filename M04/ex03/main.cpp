
#include "Ice.hpp"
#include "Cure.hpp"
#include "BlankMateria.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

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
	AMateria *copy2;


	std::cout << "cornetto: " << cornetto->getType() << std::endl;
	AMateria *aldi_cornetto = cornetto->clone();
	std::cout << "aldi cornetto: " << aldi_cornetto->getType() << std::endl;
	std::cout << "magnum: "  << magnum->getType() << std::endl;
	copy = *((Ice *)magnum);
	std::cout << "assigned copy: "  << copy.getType() << std::endl;
	// copy.use(nullptr);
	// delete cornetto;
	// delete aldi_cornetto;
	// delete magnum;
	std::cout << std::endl << std::endl;

	ICharacter *henry = new Character();
	std::cout << henry->getName() << "\n";
	henry->use(0, *henry);
	henry->use(1, *henry);
	henry->use(2, *henry);
	henry->use(3, *henry);
	henry->equip(cornetto);
	henry->equip(nullptr);
	henry->equip(cornetto);
	henry->equip(aldi_cornetto);
	henry->equip(magnum);
	copy2 = copy.clone();
	henry->equip(copy2);

	ICharacter *new_char = new Character("albert");
	ICharacter *puet = new Character(*(Character *)new_char);
	
	// henry->equip(&copy);
	henry->use(2, *henry);
	new_char->equip(cornetto->clone());
	new_char->equip(cornetto->clone());
	*(Character *)henry = *(Character *)new_char;	
	henry->use(0, *new_char);
	henry->use(1, *new_char);
	// henry->unequip(0);
	henry->unequip(1);
	// henry->unequip(1);
	// henry->unequip(3);
	// henry->unequip(3);
	// std::cout << "Items: " << items_on_floor << std::endl;

	std::cout << "Puet is now " << puet->getName() << "\n"
	<< "Henry is now " << henry->getName() << std::endl;
	delete henry;
	AMateria *medic = new Cure();
	AMateria *x = new BlankMateria("x_materia");
	AMateria *y = new BlankMateria();
	puet->equip(medic);
	puet->equip(x);
	puet->equip(y);
	puet->equip(y->clone());
	puet->use(0, *new_char);
	puet->use(1, *new_char);
	puet->use(2, *new_char);
	puet->use(3, *new_char);
	puet->unequip(3);
	puet->unequip(2);
	puet->unequip(1);
	puet->unequip(0);
	// ICharacter *new_char = new Character("albert");
	// std::cout << new_char->getName() << std::endl;

	// delete cornetto;
	// delete aldi_cornetto;
	// delete magnum;
	// delete copy2;
	
	IMateriaSource *src = new MateriaSource();
	IMateriaSource *new_src = new MateriaSource();

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new BlankMateria());
	src->learnMateria(new BlankMateria("frof"));
	src->learnMateria(new BlankMateria("fraf"));
	src->print_knowledge();
	new_src->learnMateria(new BlankMateria());
	new_src->print_knowledge();
	std::cout << "Reassigning new_src"  << std::endl;
	IMateriaSource *cpy = new MateriaSource(*(MateriaSource *)new_src);
	*(MateriaSource *)new_src = *(MateriaSource* )src;
	new_src->print_knowledge();
	std::cout << "Printing new_src cpy" << std::endl;
	cpy->print_knowledge();
	puet->equip(src->createMateria("frof"));
	puet->use(0, *new_char);
	puet->unequip(0);
	delete new_src;
	delete src;
	delete cpy;

	delete puet;
	delete new_char;

	if (items_on_floor)
	{
		std::cout << "Deleting items on the floor" << std::endl;
		for (int i = 0; items_on_floor[i] != nullptr; i++)
		{
			std::cout << i << ": "
			<< items_on_floor[i]->getType() << std::endl;
			delete items_on_floor[i];
		}
	}

	atexit(leaks_f);
}