#include "PresidentialPardonForm.hpp"
PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential Pardon Form rev1776c1", 25, 5), _target(target)
{
	std::cout << GRAY << "Shrubbery string constructor" << NO_COLOR << "\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : AForm(src), _target(src._target)
{
	std::cout << GRAY << "Shrubbery copy constructor" << NO_COLOR << "\n";
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << GRAY << "Shrubbery destructor" << NO_COLOR << "\n";
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(PresidentialPardonForm const&  rhs)
{
	// Since almost all members are constant, this is a bit superfluous.
	if(this == &rhs)
		return *this;
	this->_target = rhs._target;
	return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	executeCheck(executor.getGrade(), *this);
	
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox\n";
	return ;
}
std::string PresidentialPardonForm::getTarget(void) const
{
	return _target;
}

std::ostream &operator<<(std::ostream &os, const PresidentialPardonForm &t)
{
	os << "Form name:\t" << t.getName()
	<< "\nTarget:\t\t" << t.getTarget()
	<< "\nSign grade:\t" << t.getSignGrade()
	<< "\nExecute grade:\t" << t.getExecuteGrade()
	<< "\nSigned\t\t" << (t.isSigned() ? "yes" : "no");
	return (os);
}
