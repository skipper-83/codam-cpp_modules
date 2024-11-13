#include <iostream>
#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat low_dweller("Gimly", 150);
	Bureaucrat top_dog("Aragorn", 1);
	Bureaucrat *test;
	Bureaucrat copy_cat(top_dog);

	copy_cat.decrementGrade();
	std::cout << copy_cat << "\n";
	top_dog = copy_cat;

	try
	{
		test = new Bureaucrat("pieto", 150);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		test->decrementGrade();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	delete test;
	try
	{
		std::cout << "Incrementing grade of " << top_dog.getName() << " current grade is " << top_dog.getGrade() << std::endl;
		top_dog.incrementGrade();
		std::cout << "Succes. Grade now " << top_dog.getGrade() << std::endl;
		std::cout << "Incrementing grade of " << top_dog.getName() << " current grade is " << top_dog.getGrade() << std::endl;
		top_dog.incrementGrade();
		// it won't go here
		std::cout << "Succes. Grade now " << top_dog.getGrade() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "Decrementing grade of " << low_dweller.getName() << " current grade is " << low_dweller.getGrade() << std::endl;
		low_dweller.decrementGrade();
		// it won't go here
		std::cout << "Succes. Grade now " << top_dog.getGrade() << std::endl;

	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << top_dog << "\n";
}
