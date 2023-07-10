#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <iostream>
# include <iomanip>
# define BLUE_BG "\e[48;5;019m"
# define GRAY "\e[38;5;235m"
# define NO_COLOR "\e[0m"
# define BOLD "\033[1m"

class Contact
{
	public:
							Contact(std::string fname, std::string lname, \
									std::string nickname, std::string number, \
									std::string secret, int index);
							~Contact(void);
		void				displayAsListItem(void);
		void				displayFullContact(void);

	private:
		std::string const	_first_name;
		std::string const	_last_name;
		std::string const	_nick_name;
		std::string const	_phone_number;
		std::string const	_dark_secret;
		int					_index;
		std::string			_truncateItem(std::string str);
};

#endif