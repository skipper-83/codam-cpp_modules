// #include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"


int main(void)
{
	const	Animal* meta = new Animal();
	const	Animal* i = new Cat();
	const	Animal* j = new Dog();
	Animal	shape_shift;
	Cat		copy_cat;
	Dog		copy_dog;
	const	WrongAnimal* wrong_meta = new WrongAnimal();
	const	WrongAnimal* wrong_i = new WrongCat();

	std::cout << meta->getType() << ": ";
	meta->makeSound();
	
	std::cout << std::endl << "Making copy" << std::endl;
	Animal *copy = new Animal(*meta);
	std::cout << copy->getType() << ": ";
	copy->makeSound();
	delete copy;

	std::cout << std::endl << "Assigning copy" << std::endl;
	shape_shift = *meta;
	std::cout << shape_shift.getType() << ": ";
	shape_shift.makeSound();

	std::cout << std::endl << "Making cat meow" << std::endl;
	std::cout << i->getType() << ": ";
	i->makeSound();

	std::cout << std::endl << "Making copy" << std::endl;
	copy = new Cat(*(Cat *)(i));
	std::cout << copy->getType() << ": ";
	copy->makeSound();
	delete copy;

	std::cout << std::endl << "Reassigning copy" << std::endl;
	shape_shift = *(Cat *)i;
	std::cout << shape_shift.getType() << ": ";
	shape_shift.makeSound();

	std::cout << std::endl << "Reassigning cat copy" << std::endl;
	copy_cat = *(Cat *)i;
	std::cout << copy_cat.getType() << ": ";
	copy_cat.makeSound();

	std::cout << std::endl << "Reassigning cat copy with copy constructor" << std::endl;
	copy_cat = Cat(*(Cat *)i);
	std::cout << copy_cat.getType() << ": ";
	copy_cat.makeSound();
	std::cout << std::endl;

	std::cout << std::endl << "Making dog bark" << std::endl;
	std::cout << j->getType() << ": ";
	j->makeSound();	

	std::cout << std::endl << "Making copy" << std::endl;
	copy = new Dog(*(Dog *)(j));
	std::cout << copy->getType() << ": ";
	copy->makeSound();
	delete copy;

	std::cout << std::endl << "Reassigning copy" << std::endl;
	shape_shift = *(Dog *)j;
	std::cout << shape_shift.getType() << ": ";
	shape_shift.makeSound();

	std::cout << std::endl << "Reassigning dog copy" << std::endl;
	copy_dog = *(Dog *)j;
	std::cout << copy_dog.getType() << ": ";
	copy_dog.makeSound();

	std::cout << std::endl << "Reassigning dog copy with copy constructor" << std::endl;
	copy_dog = Dog(*(Dog *)j);
	std::cout << copy_dog.getType() << ": ";
	copy_dog.makeSound();
	std::cout << std::endl;

	std::cout << std::endl << "Wrong Cat" << std::endl;
	std::cout << wrong_meta->getType() << ": ";
	wrong_meta->makeSound();
	std::cout << wrong_i->getType() << ": ";
	wrong_i->makeSound();
	std::cout << std::endl;

	std::cout << "Freeing memory" << std::endl;
	delete meta;
	// delete copy;
	delete i;
	delete j;
	delete wrong_meta;
	delete wrong_i;
	std::cout << "Done freeing allocated memory" << std::endl;
}