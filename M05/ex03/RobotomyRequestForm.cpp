#include "RobotomyRequestForm.hpp"
RobotomyRequestform::RobotomyRequestform(std::string target) : AForm("Robotomy Request Form rev1968c1.1", 72, 45), _target(target)
{
	std::cout << GRAY << "Shrubbery string constructor" << NO_COLOR << "\n";
}

RobotomyRequestform::RobotomyRequestform(const RobotomyRequestform &src) : AForm(src), _target(src._target)
{
	std::cout << GRAY << "Shrubbery copy constructor" << NO_COLOR << "\n";
}

RobotomyRequestform::~RobotomyRequestform()
{
	std::cout << GRAY << "Shrubbery destructor" << NO_COLOR << "\n";
}

RobotomyRequestform&	RobotomyRequestform::operator=(RobotomyRequestform const&  rhs)
{
	// Since almost all members are constant, this is a bit superfluous.
	if(this == &rhs)
		return *this;
	this->_target = rhs._target;
	return *this;
}

void RobotomyRequestform::execute(const Bureaucrat &executor) const
{
	executeCheck(executor.getGrade(), *this);
	
	static bool	rand_seeded = false;
	if (!rand_seeded)
	{
		srand((unsigned) time(0));
		rand_seeded = true;
	}
	int	rand = std::rand() % 2;
	std::cout << "\n\nBZZZZGGRRRRRRHHHBBBBRBRRRBRBBBNBBBBB\n";
	usleep(300000);
	std::cout << ".\n";
	usleep(400000);
	std::cout << ".\n";
	usleep(500000);
	std::cout << ".\n";
	usleep(600000);
	std::cout << ".\n";
	usleep(700000);
	std::cout << ".\n";
	if (rand)
		std::cout << "Robotomy of " << _target << " succeeded. May they rest in peace\n";
	else
		std::cout << "Robotomy failed! Try again later.\n";
	return ;
}
std::string RobotomyRequestform::getTarget(void) const
{
	return _target;
}

std::ostream &operator<<(std::ostream &os, const RobotomyRequestform &t)
{
	os << "Form name:\t" << t.getName()
	<< "\nTarget:\t\t" << t.getTarget()
	<< "\nSign grade:\t" << t.getSignGrade()
	<< "\nExecute grade:\t" << t.getExecuteGrade()
	<< "\nSigned\t\t" << (t.isSigned() ? "yes" : "no");
	return (os);
}
