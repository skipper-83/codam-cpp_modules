#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>

# define GRAY "\e[38;5;243m"
# define NO_COLOR "\e[0m"

# define MAX_GRADE 1
# define MIN_GRADE 150

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