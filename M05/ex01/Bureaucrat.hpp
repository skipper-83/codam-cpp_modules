#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>

# include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		const std::string 	_name;
		int					_grade;

		Bureaucrat();
	
	public:
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat &src);
		~Bureaucrat(void);


		int			getGrade(void) const;
		std::string	getName(void) const;

		void		signForm(Form& form);
		void		incrementGrade(void);
		void		decrementGrade(void);

		Bureaucrat & operator=(const Bureaucrat &rhs);

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

std::ostream &operator<<(std::ostream &os, const Bureaucrat &t);

#endif