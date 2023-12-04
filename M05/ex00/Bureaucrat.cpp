#include "Bureaucrat.hpp"

static void	testGrade(int grade)
{
	if (grade < MAX_GRADE)
		throw (Bureaucrat::GradeTooHighException());
	if (grade > MIN_GRADE)
		throw (Bureaucrat::GradeTooLowException());
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade)
{
	std::cout << GRAY << "Bureaucrat string constructor" << NO_COLOR << "\n";
	testGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src._name), _grade(src._grade)
{
	std::cout << GRAY << "Bureaucrat copy constructor" << NO_COLOR << "\n";
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << GRAY << "Bureaucrat destructor" << NO_COLOR << "\n";
}

int Bureaucrat::getGrade(void) const
{
	return this->_grade;
}

std::string Bureaucrat::getName(void) const
{
	return this->_name;
}

void Bureaucrat::incrementGrade(void)
{
	testGrade(_grade - 1);
	(this->_grade)--;
}

void Bureaucrat::decrementGrade(void)
{
	testGrade(this->_grade + 1);
	(this->_grade)++;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
	std::cout << GRAY << "Bureaucrat copy assignment operator" << NO_COLOR << "\n";
	if (this == &rhs)
		return *this;
	this->_grade = rhs._grade;
	return *this;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &t)
{
	os << t.getName() << ", bureaucrat grade " << t.getGrade();
	return (os);
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}
