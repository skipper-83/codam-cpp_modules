#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	ShrubberyCreationForm form("somehere");
	Bureaucrat	chief("Keanu", 10);
	Bureaucrat	dweller("Stefano", 149);

	std::cout << form << "\n";
	try	{	form.execute(chief); 	}
	catch(const std::exception& e)
	{	std::cerr << e.what() << '\n'; }
	chief.signForm(form);
	try	{	form.execute(dweller); 	}
	catch(const std::exception& e)
	{	std::cerr << e.what() << '\n'; }
	try	{	form.execute(chief); 	}
	catch(const std::exception& e)
	{	std::cerr << e.what() << '\n'; }
	dweller.executeForm(form);
	chief.executeForm(form);

	ShrubberyCreationForm form2("anywehere");
	chief.executeForm(form2);
	dweller.signForm(form2);
	chief.signForm(form2);
	chief.executeForm(form2);

	RobotomyRequestform robby("innocent victim");
	chief.executeForm(robby);
	chief.signForm(robby);
	chief.executeForm(robby);
	// chief.executeForm(robby);

	PresidentialPardonForm pardon_me("The Don");
	Bureaucrat deity("Higher Form of Being", 1);
	dweller.signForm(pardon_me);
	chief.signForm(pardon_me);
	chief.executeForm(pardon_me);
	deity.executeForm(pardon_me);
	
}


