#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <map>
# include <string>
# include <string_view>

class	Harl
{
	public:
									Harl();
									~Harl();
		void						complain(std::string level);
	
	private:
		void						debug(void) ;
		void						info(void)	;
		void						warning(void) ;
		void						error(void) ;
		std::map<std::string, int>	level_lut;
		void						(Harl::*complain_funcs[5])(void);
};

#endif