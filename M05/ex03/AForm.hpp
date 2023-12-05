#ifndef AFORM_HPP
# define AFORM_HPP
# include <iostream>
# include "Bureaucrat.hpp"

# define GRAY "\e[38;5;243m"
# define NO_COLOR "\e[0m"

# define MAX_GRADE 1
# define MIN_GRADE 150

class Bureaucrat;

class AForm
{
	private:
		AForm();

		const int			_signGrade;
		const int			_executeGrade;
		const std::string	_name;	
		bool				_isSigned;
	
	protected:
		void			testGradeWithinBounds(int grade) const;
		void			executeCheck(int grade, AForm const& form) const;

	public:
						AForm(const std::string &name, const int &signGrade, const int &executeGrade);
						AForm(const AForm& src);
						virtual	~AForm(void);

		void			beSigned(Bureaucrat &signee);
		std::string		getName(void) const;
		int				getSignGrade(void) const;
		int				getExecuteGrade(void) const;
		bool			isSigned(void) const;
		AForm&			operator=(const AForm& rhs);

		virtual void	execute(const Bureaucrat& executor) const = 0;

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
		class NotSignedException : public std::exception
		{
			public:
				const char* what() const throw();
		};

};

std::ostream&	operator<<(std::ostream& os, const AForm& t);

#endif