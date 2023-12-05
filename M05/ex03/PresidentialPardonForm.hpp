#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class PresidentialPardonForm : public AForm
{
	private:
		std::string	_target;
		PresidentialPardonForm();

	public:
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& src);
		~PresidentialPardonForm();

		PresidentialPardonForm&	operator=(PresidentialPardonForm const&  rhs);

		void		execute(const Bureaucrat& executor) const;
		std::string	getTarget(void) const;
};

std::ostream&	operator<<(std::ostream& os, const PresidentialPardonForm& t);

#endif