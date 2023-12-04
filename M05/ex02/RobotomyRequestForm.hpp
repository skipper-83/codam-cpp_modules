#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <fstream>
#include <random>
#include <unistd.h>

class RobotomyRequestform : public AForm
{
	private:
		std::string	_target;
		RobotomyRequestform();

	public:
		RobotomyRequestform(std::string target);
		RobotomyRequestform(const RobotomyRequestform& src);
		~RobotomyRequestform();

		RobotomyRequestform&	operator=(RobotomyRequestform const&  rhs);

		void		execute(const Bureaucrat& executor) const;
		std::string	getTarget(void) const;
};

std::ostream&	operator<<(std::ostream& os, const RobotomyRequestform& t);
#endif