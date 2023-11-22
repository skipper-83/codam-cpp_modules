// #include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main(void)
{
	Animal*	animals[4];
	Animal*	doggie = new Dog();
	Animal*	cattie = new Cat();
	Animal	generic = Animal();
// 
	// atexit(leaks_f);
	generic.setIdea(1, "new idea");
	std::cout << generic.getIdea(1) << std::endl;
	generic.brainDump();
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
	std::cout <<"CHECKING DEEP COPY\n\n"<< cattie->getIdea(22) << "\n";
	Cat copy_cattie = Cat(*(Cat *)cattie);	
	cattie->setIdea(22, "catched 22");
	std::cout << copy_cattie.getIdea(22) << "\n" << cattie->getIdea(22) << "\n";
	Dog copy_dog = Dog(*(Dog *)doggie);
	doggie->setIdea(1, "Tell me what to do");
	std::cout << copy_dog.getIdea(1) << "\n" << doggie->getIdea(1) << "\n";
 	delete cattie;
	delete doggie;
}