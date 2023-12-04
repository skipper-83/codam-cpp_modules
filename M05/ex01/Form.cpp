#include "Form.hpp"

static void	testGrade(int grade)
{
	if (grade < MAX_GRADE)
		throw (Form::GradeTooHighException());
	if (grade > MIN_GRADE)
		throw (Form::GradeTooLowException());
}

Form::Form(const std::string &name, const int &signGrade, const int &executeGrade) : _name(name), _signGrade(signGrade), _executeGrade(executeGrade)
{
	std::cout << GRAY << "Form string constructor" << NO_COLOR << "\n";
	_isSigned = false;
	testGrade(signGrade);
	testGrade(executeGrade);
}

Form::Form(const Form &src)  : _name(src._name), _signGrade(src._signGrade), _executeGrade(src._executeGrade), _isSigned(src._isSigned)
{
	std::cout << GRAY << "Form copy constructor" << NO_COLOR << "\n";
}

Form::~Form(void)
{
	std::cout << GRAY << "Form destructor" << NO_COLOR << "\n";
}

void Form::beSigned(Bureaucrat &signee)
{
	if(signee.getGrade() > this->_signGrade)
		throw (GradeTooLowException());
	this->_isSigned = true;
}

std::string Form::getName(void) const
{
	return this->_name;
}

int Form::getSignGrade(void) const
{
	return this->_signGrade;
}

int Form::getExecuteGrade(void) const
{
	return this->_executeGrade;
}

bool Form::isSigned(void) const
{
	return this->_isSigned;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

Form &Form::operator=(const Form &rhs)
{
	std::cout << GRAY << "Form copy assignment operator" << NO_COLOR << "\n";
	if (this == &rhs)
		return *this;
	this->_isSigned = rhs._isSigned;
	return *this;
}

std::ostream &operator<<(std::ostream &os, const Form &t)
{
	os << "Form name:\t" << t.getName()
	<< "\nSign grade:\t" << t.getSignGrade()
	<< "\nExecute grade:\t" << t.getExecuteGrade()
	<< "\nSigned\t\t" << (t.isSigned() ? "yes" : "no");
	return (os);
}
