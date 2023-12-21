#include <iostream>
#include "Bureaucrat.hpp"


int main(void)
{
	Bureaucrat	low_dweller("Gimly", 150);
	Bureaucrat	top_dog("Aragorn", 1);
	Bureaucrat	*test;
	Bureaucrat	copy_cat(top_dog);

	copy_cat.decrementGrade();
	std::cout << copy_cat << "\n";
	top_dog = copy_cat;


	try
	{
		test = new Bureaucrat("pieto", 150);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		test->decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	delete test;
	try
	{
		top_dog.incrementGrade();
		top_dog.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		low_dweller.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << top_dog << "\n";
}


