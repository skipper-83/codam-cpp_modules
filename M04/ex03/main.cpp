
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

// void	leaks_f()
// {
// 	system ("leaks -q materia");
// }

int main(void)
{
	// atexit(leaks_f);
	std::cout << "ICE CONSTRUCTOR TESTS\n\n";
	std::cout << "Standard constructor\n";
	AMateria *ice = new Ice();
	std::cout << "Copy constructor\n";
	AMateria *ice_copy = new Ice(*(Ice *)ice);
	Ice ice_assigned;
	std::cout << "Copy assignment operator\n";
	ice_assigned = *(Ice *)ice;
	std::cout << "standard\t" << ice << ":\t"
	<< ice->getType() << "\n"
	<< "copy\t\t" << ice_copy << ":\t"
	<< ice_copy->getType() << "\n"
	<< "assigned\t" << &ice_assigned << ":\t"
	<< ice_assigned.getType() << "\n";
	delete ice;
	delete ice_copy;
	std::cout << "END ICE CONSTRUCTOR TESTS\n\n";


	std::cout << "CURE CONSTRUCTOR TESTS\n\n";
	std::cout << "Standard constructor\n";
	AMateria *cure = new Cure();
	std::cout << "Copy constructor\n";
	AMateria *cure_copy = new Cure(*(Cure *)cure);
	Cure cure_assigned;
	std::cout << "Copy assignment operator\n";
	cure_assigned = *(Cure *)cure;
	std::cout << "standard\t" << cure << ":\t"
	<< cure->getType() << "\n"
	<< "copy\t\t" << cure_copy << ":\t"
	<< cure_copy->getType() << "\n"
	<< "assigned\t" << &cure_assigned << ":\t"
	<< cure_assigned.getType() << "\n";
	delete cure_copy;
	delete cure;
	std::cout << "END CURE CONSTRUCTOR TESTS\n\n";

	std::cout << "CHARACTER CONSTRUCTOR TESTS\n\n";
	std::cout << "Standard constructor\n";
	ICharacter *standard_char = new Character();
	std::cout << "equipping...\n";
	standard_char->equip(new Ice());
	std::cout << "using...\n";
	standard_char->use(0, *standard_char);
	std::cout << "String constructor\n";
	ICharacter *string_char = new Character("Mr Blue");
	std::cout << "equipping...\n";
	string_char->equip(new Cure());
	string_char->equip(new Ice());
	std::cout << "using...\n";
	string_char->use(0, *standard_char);
	std::cout << "Copy constructor\n";
	ICharacter *copy_char = new Character(*(Character *)standard_char);
	std::cout << "Copy done. Original: " << standard_char 
	<< ". Copy: " << copy_char
	<< "Using item...\n";
	standard_char->use(0, *standard_char);
	std::cout << "Copy assignment operator\n";
	Character assigned_char;
	assigned_char = *(Character *)string_char;
	std::cout << "Assignment done. Original: " << string_char
	<< ". Copy: " << &assigned_char
	<< "Using item...\n";
	assigned_char.use(0, *string_char);
	assigned_char.use(1, *string_char);
	std::cout << "Unequipping item on index 1\n";
	assigned_char.unequip(1);
	std::cout << "Reassigning...\n";
	assigned_char = *(Character *)standard_char;
	std::cout << "Reassignment done. Original: " << standard_char
	<< ". Copy: " << &assigned_char
	<< "Using item...\n";
	assigned_char.use(0, *string_char);
	delete standard_char;
	delete string_char;
	delete copy_char;
	std::cout << "Unequipping from stack character\n";
	assigned_char.unequip(0);
	std::cout << "END CHARACTER CONSTRUCTOR TESTS\n\n";


	std::cout << "MATERIASOURCE CONSTRUCTOR TESTS\n\n";		
	std::cout << "Standard constructor\n";
	IMateriaSource *source = new MateriaSource();
	source->learnMateria(new Ice());
	std::cout << "Copy constructor\n";
	IMateriaSource *source_copy = new MateriaSource(*(MateriaSource *)source);
		std::cout << "Copy done. Original: " << standard_char
	<< ". Copy: " << copy_char << "\n";
	AMateria *tmp_from_original = source->createMateria("ice");;
	AMateria *tmp_from_copy = source_copy->createMateria("ice");
	std::cout << "Original: " << tmp_from_original->getType() << "\n"
	<< "Copy: " << tmp_from_copy->getType() << "\n";
	delete tmp_from_original;
	std::cout << "WRONG INPUTS FOR MATERIASOURCE\n";
	tmp_from_original = source->createMateria("oops");
	source->learnMateria(nullptr);
	source->learnMateria(new Ice());
	source->learnMateria(new Ice());
	source->learnMateria(new Ice());
	source->learnMateria(new Ice());
	std::cout << "END WRONG INPUTS FOR MATERIASOURCE\n";
	std::cout << "Copy assignment operator\n";
	MateriaSource source_assigned = *(MateriaSource *)source;
	std::cout <<"Assigment done, creating from assigned...\n";
	AMateria *tmp_from_assigned = source_assigned.createMateria("ice");
	delete tmp_from_assigned;
	delete tmp_from_original;
	delete tmp_from_copy;
	delete source;
	delete source_copy;
	std::cout << "END MATERIASOURCE CONSTRUCTOR TESTS\n\n";

	std::cout << "SUBJECT TESTS\n\n";
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	std::cout << "END SUBJECT TESTS\n\n";

	if (items_on_floor)
	{
		std::cout << "DELETING ITEMS ON THE FLOOR" << std::endl;
		for (int i = 0; items_on_floor[i] != nullptr; i++)
		{
			std::cout << i << ": "
			<< items_on_floor[i]->getType() << std::endl;
			delete items_on_floor[i];
		}
		delete [] items_on_floor;
	}
	std::cout << "\n\nDELETING STACK ALLOCATED CLASSES\n";

	// AMateria *ntest = new Ice();
	// std::cout << "Printing test: " << ntest << " reinterpret cast: " ntest) <<"\n";
	// delete ntest;
}