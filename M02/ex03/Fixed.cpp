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
	return(this->_value >> _fractional_bits);
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_value / (1 << _fractional_bits));
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
	this->_value = n << _fractional_bits;
	return ;
}

Fixed::Fixed(float const n)
{
	this->_value = roundf((n *( 1 <<_fractional_bits)));
	// std::cout <<  GRAY<<"Float constructor called"NO_COLOR << std::endl;
	return ;
}

Fixed::Fixed(Fixed const& src)
{
	//  std::cout << GRAY"Copy constructor called"NO_COLOR << std::endl;
	 this->_value = src.getRawBits();
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
	Fixed	res(this->toFloat()  / b.toFloat());
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
