#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
        std::cout << GRAY << "Intern standard constructor\n" << NO_COLOR;
}

Intern::Intern(Intern const &src)
{
    std::cout << GRAY << "Intern copy constructor\n" << NO_COLOR;
}

Intern::~Intern()
{
      std::cout << GRAY << "Intern destructor\n" << NO_COLOR;
}

Intern &Intern::operator=(Intern const &rhs)
{
    std::cout << GRAY << "Intern copy assignment operator\n" << NO_COLOR;
	// Interns are so generic you can copy them right away.
    return (*this);
}

AForm* Intern::makeForm(std::string const &name, std::string const &target) 
{
	AForm *ret;
	std::string	supported_forms[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	AForm* (Intern::*form_constructors[3])(std::string const&) = {
		&Intern::_makeShrubbery,
		&Intern::_makeRobotomy,
		&Intern::_makePardon
	};
	for(int i = 0; i < 3; i++)
	{
		if (name == supported_forms[i])
		{
			ret = (this->*form_constructors[i])(target);
			std::cout << "Intern creates " << ret->getName() << " because it received [" << name << "] as a request\n";
			return ret;
		}
	}
	std::cout << "Intern cannot create form: form [" << name <<"] does not exist in form registry\n";
	return nullptr;
}

AForm *Intern::_makeShrubbery(std::string const &target)
{
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::_makeRobotomy(std::string const &target)
{
	return (new RobotomyRequestform(target));
}

AForm *Intern::_makePardon(std::string const &target)
{
	return (new PresidentialPardonForm(target));
}
