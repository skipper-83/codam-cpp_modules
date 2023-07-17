#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# define GRAY "\e[38;5;243m"
# define NO_COLOR "\e[0m"

class Fixed
{
	public:
		Fixed(void);
		~Fixed();
		Fixed(Fixed const& src);

		Fixed&	operator=(Fixed const& src);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
	
	private:
		int					_value;
		static const int	_fractional_bits;

};

#endif