#include "Fixed.hpp"

const int	Fixed::_fractional_bits = 8;

int	Fixed::getRawBits(void) const
{
	// std::cout << GRAY"getRawBits member function called"NO_COLOR << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits(int raw)
{
	// std::cout << GRAY"setRawBits member function called"NO_COLOR << std::endl;
	this->_value = raw;
}

int	Fixed::toInt(void) const
{
	return(this->_value >> 8);
}

float	Fixed::toFloat(void) const
{
	float	res;
	float	cur_bit;

	res = this->_value >> 8;
	for (int i = 1; i <= _fractional_bits; i++)
	{
		cur_bit = pow(2, -i);
		if (this->_value & 1 << (_fractional_bits - i))
			res += cur_bit;
	}
	return (res);
}

Fixed::Fixed(void)
{
	this->_value = 0;
	// std::cout << GRAY"Default constructor called"NO_COLOR << std::endl;
	return ;
}

Fixed::Fixed(int const n)
{
	// std::cout <<  GRAY<<"Int constructor called"NO_COLOR << std::endl;
	this->_value = n << 8;
	return ;
}

Fixed::Fixed(float const n)
{
	float	fractional;
	float	cur_bit;
	int		raw_bit;
	
	// std::cout <<  GRAY<<"Float constructor called"NO_COLOR << std::endl;
	fractional = n - (int)n;
	raw_bit = (int)n << 8;
	for (int i = 1; i <= _fractional_bits; i++)
	{
		cur_bit = pow(2, -i);
		if (fractional >= cur_bit)
		{
			fractional -= cur_bit;
			raw_bit |= 1 << (_fractional_bits - i);
		}
	}
	this->_value = raw_bit;
	return ;
}

Fixed::Fixed(Fixed const& src)
{
	//  std::cout << GRAY"Copy constructor called"NO_COLOR << std::endl;
	 this->_value = src.getRawBits();
	 return ;
}

Fixed::~Fixed()
{
	// std::cout << GRAY"Destructor called"NO_COLOR << std::endl;
	return ;
}

Fixed&	Fixed::operator=(Fixed const& src)
{
	// std::cout << GRAY"Copy assignment operator called"NO_COLOR << std::endl;
	this->_value = src.getRawBits();
	return (*this);
}

/*
 *
 * ARITHMETIC OPERATORS
 * 
*/

Fixed	Fixed::operator+(Fixed const& b)
{
	Fixed	res;
	res._value = this->_value + b._value;
	return (res);
}

Fixed	Fixed::operator-(Fixed const& b)
{
	Fixed	res;
	res._value = this->_value - b._value;
	return (res);
}

Fixed	Fixed::operator*(Fixed const& b)
{
	Fixed	res;
	res._value = this->_value * b._value;
	res._value = res._value >> 8;
	return (res);
}

Fixed	Fixed::operator/(Fixed const& b)
{
	Fixed	res((float)this->_value  / (float)b._value);
	return (res);
}

/*
 *
 * COMPARISON OPERATORS
 * 
*/

bool	Fixed::operator==(Fixed const& b) const
{
	return(this->_value == b._value);
}

bool	Fixed::operator!=(Fixed const& b) const
{
	return(this->_value != b._value);
}

bool	Fixed::operator>(Fixed const& b) const
{
	return(this->_value > b._value);
}

bool	Fixed::operator<(Fixed const& b) const
{
	return(this->_value < b._value);
}

bool	Fixed::operator>=(Fixed const& b) const
{
	return(this->_value >= b._value);
}

bool	Fixed::operator<=(Fixed const& b) const
{
	return(this->_value <= b._value);
}

/*
 *
 * INCREMENT OPERATORS
 * 
*/

Fixed	Fixed::operator++(void)
{
	++(this->_value);
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp;

	tmp._value = this->_value;
	++(this->_value);
	return tmp;
}

Fixed	Fixed::operator--(void)
{
	--(this->_value);
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp;

	tmp._value = this->_value;
	--(this->_value);
	return tmp;
}

/*
 *
 * MIN/MAX
 * 
*/

Fixed&		Fixed::max(Fixed& a, Fixed& b)
{
	std::cout << "nonconst max ";
	if (a > b)
		return (a);
	return b;
}

Fixed&		Fixed::min(Fixed& a, Fixed& b)
{
	std::cout << "nonconst min ";
	if (a < b)
		return (a);
	return b;
}

Fixed const&		Fixed::max(Fixed const& a, Fixed const& b)
{
	std::cout << "const max ";
	if (a > b)
		return (a);
	return b;
}

Fixed const&		Fixed::min(Fixed const& a, Fixed const& b)
{
	std::cout << "const min ";
	if (a < b)
		return (a);
	return b;
}

/*
 *
 * IOSTREAM
 * 
*/

std::ostream& operator<<(std::ostream &os, Fixed const& t)
{
	os << t.toFloat();
	return (os);
}
