#ifndef INTERN_HPP
# define INTERN_HPP
# include "AForm.hpp"

class Intern
{
    public:
        Intern();
        Intern(Intern const& src);
        ~Intern();

        Intern& operator=(Intern const& rhs);
		AForm*	makeForm(std::string const &name, std::string const &target) ;
	
	private:
		AForm*	_makeShrubbery(std::string const &target);
		AForm*	_makeRobotomy(std::string const &target);
		AForm*	_makePardon(std::string const &target);
};

#endif