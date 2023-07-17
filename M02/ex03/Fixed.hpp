#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <iomanip>
# include <cmath>
# define GRAY "\e[38;5;243m"
# define NO_COLOR "\e[0m"

class Fixed
{
	public:
								Fixed(void);
								Fixed(const int n);
								Fixed(const float n);
								~Fixed();
								Fixed(Fixed const& src);

		Fixed&					operator=(Fixed const& src);

		int						getRawBits(void) const;
		void					setRawBits(int const raw);

		int						toInt(void) const;
		float					toFloat(void) const;

		Fixed					operator+(Fixed const& b);
		Fixed					operator-(Fixed const& b);
		Fixed					operator*(Fixed const& b);
		Fixed					operator/(Fixed const& b);

		Fixed					operator++(void);
		Fixed					operator++(int);
		Fixed					operator--(void);
		Fixed					operator--(int);

		bool					operator==(Fixed const& b) const;
		bool					operator!=(Fixed const& b) const;
		bool					operator>(Fixed const& b) const;
		bool					operator<(Fixed const& b) const;
		bool					operator>=(Fixed const& b) const;
		bool					operator<=(Fixed const& b) const;

		static Fixed&			max(Fixed& a, Fixed& b);
		static Fixed&			min(Fixed& a, Fixed& b);
		static Fixed const&		max(Fixed const& a, Fixed const& b);
		static Fixed const&		min(Fixed const& a, Fixed const& b);
		
	
	private:
		int						_value;
		static const int		_fractional_bits;

};

std::ostream&	operator<<(std::ostream& os, Fixed const& t);

#endif