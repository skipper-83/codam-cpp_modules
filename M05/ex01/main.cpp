#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"


int main(void)
{
	Form		my_form("28c", 20, 2);
	Form		copy_form(my_form);
	Bureaucrat	low_rat("Snarky", 150);
	Bureaucrat	middle_guy("John Smith", 15);

	std::cout << my_form << "\n";
	try
	{
		my_form.beSigned(low_rat);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\n" << my_form << "\n";
	try
	{
		my_form.beSigned(middle_guy);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\n" << my_form << "\n";
	std::cout << "\n\n" << copy_form << "\n\n";
	low_rat.signForm(copy_form);
	std::cout << "\n" << copy_form << "\n\n";
	middle_guy.signForm(copy_form);
	std::cout << "\n\n" << copy_form << "\n";

	
}


