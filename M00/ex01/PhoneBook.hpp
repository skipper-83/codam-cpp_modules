#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# define ENTRIES 8
# define BLUE_BG "\e[48;5;019m"
# define GRAY "\e[38;5;235m"
# define NO_COLOR "\e[0m"

# include "Contact.hpp"
# include <iomanip>
# include <iostream>

class PhoneBook
{
	public:
					PhoneBook(void);
					~PhoneBook(void);
		void		addContact(void);
		void		searchContact(void);
		
	private:
		int	_idx;
		std::string _getInput(std::string);
		void 		_showList(void);
		Contact*	_contacts[8];
};
#endif