#include "AForm.hpp"

void	AForm::testGradeWithinBounds(int grade) const
{
	if (grade < MAX_GRADE)
		throw (AForm::GradeTooHighException());
	if (grade > MIN_GRADE)
		throw (AForm::GradeTooLowException());
}

void	AForm::executeCheck(int grade, AForm const&form) const
{
	if (!form.isSigned())
		throw (AForm::NotSignedException());
	if (grade > form.getExecuteGrade())
		throw (AForm::GradeTooLowException());
}

AForm::AForm(const std::string &name, const int &signGrade, const int &executeGrade) : _name(name), _signGrade(signGrade), _executeGrade(executeGrade)
{
	std::cout << GRAY << "AForm string constructor" << NO_COLOR << "\n";
	_isSigned = false;
	testGradeWithinBounds(signGrade);
	testGradeWithinBounds(executeGrade);
}

AForm::AForm(const AForm &src)  : _name(src._name), _signGrade(src._signGrade), _executeGrade(src._executeGrade), _isSigned(src._isSigned)
{
	std::cout << GRAY << "AForm copy constructor" << NO_COLOR << "\n";
}

AForm::~AForm(void)
{
	std::cout << GRAY << "AForm destructor" << NO_COLOR << "\n";
}

void AForm::beSigned(Bureaucrat &signee)
{
	if(signee.getGrade() > this->_signGrade)
		throw (GradeTooLowException());
	this->_isSigned = true;
}

std::string AForm::getName(void) const
{
	return this->_name;
}

int AForm::getSignGrade(void) const
{
	return this->_signGrade;
}

int AForm::getExecuteGrade(void) const
{
	return this->_executeGrade;
}

bool AForm::isSigned(void) const
{
	return this->_isSigned;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

const char *AForm::NotSignedException::what() const throw()
{
	return "Cannot execute: form not signed";
}

AForm &AForm::operator=(const AForm &rhs)
{
	std::cout << GRAY << "AForm copy assignment operator" << NO_COLOR << "\n";
	if (this == &rhs)
		return *this;
	this->_isSigned = rhs._isSigned;
	return *this;
}

std::ostream &operator<<(std::ostream &os, const AForm &t)
{
	os << "AForm name:\t" << t.getName()
	<< "\nSign grade:\t" << t.getSignGrade()
	<< "\nExecute grade:\t" << t.getExecuteGrade()
	<< "\nSigned\t\t" << (t.isSigned() ? "yes" : "no");
	return (os);
}
