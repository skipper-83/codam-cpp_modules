
	#include "Ice.hpp"
	#include "Cure.hpp"
	#include "Character.hpp"
	#include "MateriaSource.hpp"

	int main(void)
	{
		std::cout << "ICE CONSTRUCTOR TESTS\n\n";
		std::cout << "Standard constructor\n";
		AMateria *ice = new Ice();
		std::cout << "Copy constructor\n";
		AMateria *ice_copy = new Ice(*(Ice *)ice);
		Ice ice_assigned;
		std::cout << "Copy assignment operator\n";
		ice_assigned = *(Ice *)ice;
		printf("standard\t%p:\t", ice);
		std::cout << ice->getType() << "\n";
		printf("copy\t\t%p:\t", ice_copy);
		std::cout << ice_copy->getType() << "\n";
		printf("assigned\t%p:\t", &ice_assigned);
		std::cout << ice_assigned.getType() << "\n";
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
		printf("standard\t%p:\t", cure);
		std::cout << cure->getType() << "\n";
		printf("copy\t\t%p:\t", cure_copy);
		std::cout << cure_copy->getType() << "\n";
		printf("assigned\t%p:\t", &cure_assigned);
		std::cout << cure_assigned.getType() << "\n";
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
		printf("Copy done. Original: %p. Copy: %p. Using item...\n", standard_char, copy_char);
		standard_char->use(0, *standard_char);
		std::cout << "Copy assignment operator\n";
		Character assigned_char;
		assigned_char = *(Character *)string_char;
		printf("Assignment done. Original: %p. Copy: %p. Using item...\n", string_char, &assigned_char);
		assigned_char.use(0, *string_char);
		assigned_char.use(1, *string_char);
		std::cout << "Unequipping item on index 1\n";
		assigned_char.unequip(1);
		std::cout << "Reassigning...\n";
		assigned_char = *(Character *)standard_char;
		printf("Assignment done. Original: %p. Copy: %p. Using item...\n", standard_char, &assigned_char);
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
		printf("Copy done. Original: %p, copy: %p\n", source, source_copy);
		AMateria *tmp_from_original = source->createMateria("ice");;
		AMateria *tmp_from_copy = source_copy->createMateria("ice");
		std::cout << "Original: " << tmp_from_original->getType() << "\n"
		<< "Copy: " << tmp_from_copy->getType() << "\n";
		delete tmp_from_original;
		tmp_from_original = source->createMateria("oops");
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

		// delete [] items_on_floor;
		if (items_on_floor)
		{
			std::cout << "DELETING ITEMS ON THE FLOOR" << std::endl;
			for (int i = 0; items_on_floor[i] != nullptr; i++)
			{
				std::cout << i << ": "
				<< ((AMateria *)items_on_floor[i])->getType() << std::endl;
				delete (AMateria *)items_on_floor[i];
			}
			// free(items_on_floor);
			delete items_on_floor;
		}
		std::cout << "\n\nDELETING STACK ALLOCATED CLASSES\n";
	}