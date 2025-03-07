// #include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"


int main(void)
{
	AAnimal*	animals[4];
	AAnimal*	j = new Dog();
	AAnimal*	i = new Cat();
	// AAnimal*	animal = new AAnimal();
	// AAnimal*	wrong = new Animal();

	// atexit(leaks_f);
	for (int i = 0; i < 4; i ++)
	{
		if (i % 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
		std::cout << animals[i]->getType() << ": " << std::endl << "\t-> ";
		animals[i]->makeSound();
		std::cout << "\t-> " << animals[i]->getIdea(0) << std::endl;
		animals[i]->setIdea(1, "I got idea " + std::to_string(i));
	}
	std::cout << std::endl << "Displaying changed minds" << std::endl;
	for (int i = 0; i < 4; i ++)
	{
		std::cout << animals[i]->getType() << ": " << std::endl << "\t-> ";
		animals[i]->makeSound();
		std::cout << "\t-> " << animals[i]->getIdea(1)  << std::endl;
	}

	std::cout << std::endl << "Dumping brain one" << std::endl;
	animals[0]->setIdea(44, "the number 44 popped into this spot, would that be an idea?");
	animals[0]->brainDump();
	std::cout << std::endl << "Dumping brain two" << std::endl;
	for(int i = 0; i < 100; i++)
		animals[1]->setIdea(i, "bark.");
	animals[1]->brainDump();

	for (int i=0; i<4; i++)
		delete animals[i];
	AAnimal *copy_cat = new Cat(*(Cat *)i);
	i->setIdea(1, "now we got a new idea on pos 1");
	std::cout << i->getIdea(1) << "\n" << copy_cat->getIdea(1) << std::endl;
	delete copy_cat;
	delete i;
	delete j;
}