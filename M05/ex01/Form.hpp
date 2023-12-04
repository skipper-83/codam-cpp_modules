#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# include "Bureaucrat.hpp"

# define GRAY "\e[38;5;243m"
# define NO_COLOR "\e[0m"

# define MAX_GRADE 1
# define MIN_GRADE 150

class Bureaucrat;

class Form
{
	private:
		Form();

		const int			_signGrade;
		const int			_executeGrade;
		const std::string	_name;	
		bool				_isSigned;
	
	public:
				Form(const std::string &name, const int &signGrade, const int &executeGrade);
				Form(const Form& src);
				~Form(void);

		void		beSigned(Bureaucrat &signee);
		std::string	getName(void) const;
		int			getSignGrade(void) const;
		int			getExecuteGrade(void) const;
		bool		isSigned(void) const;
		Form&		operator=(const Form& rhs);

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};

};

std::ostream&	operator<<(std::ostream& os, const Form& t);

#endif