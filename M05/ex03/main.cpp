#include <iostream>
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"


void leaks_f()
{
	system("leaks -q bureaucrat_with_abstract_form");
}

int main(void)
{
	Intern	legal_slave;
	AForm	*form1, *form2, *form3, *form4;
	Bureaucrat	anton("Anton", 5);

	
	atexit(leaks_f);
	form1 = legal_slave.makeForm("shrubbery creation", "Garden");
	form2 = legal_slave.makeForm("robotomy request", "Self");
	form3 = legal_slave.makeForm("presidential pardon", "Barabas");
	form4 = legal_slave.makeForm("useful paperwork", "Important Matters");
	anton.signForm(*form1);
	anton.executeForm(*form1);
	anton.signForm(*form2);
	anton.executeForm(*form2);
	anton.signForm(*form3);
	anton.executeForm(*form3);
	delete form1;
	delete form2;
	delete form3;
	delete form4;
}


