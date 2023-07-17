#include "Fixed.hpp"

const int	Fixed::_fractional_bits = 8;

int	Fixed::getRawBits(void) const
{
	std::cout << GRAY"getRawBits member function called"NO_COLOR << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits(int raw)
{
	std::cout << GRAY"setRawBits member function called"NO_COLOR << std::endl;
	this->_value = raw;
	return ;
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
	std::cout << GRAY"Default constructor called"NO_COLOR << std::endl;
	return ;
}

Fixed::Fixed(int const n)
{
	std::cout <<  GRAY<<"Int constructor called"NO_COLOR << std::endl;
	this->_value = n << _fractional_bits;
	return ;
}

Fixed::Fixed(float const n)
{

	this->_value = roundf((n *( 1 <<_fractional_bits)));
	std::cout <<  GRAY<<"Float constructor called"NO_COLOR << std::endl;
	return ;
}

Fixed::Fixed(Fixed const& src)
{
	 std::cout << GRAY"Copy constructor called"NO_COLOR << std::endl;
	 this->_value = src.getRawBits();
	 return ;
}

Fixed::~Fixed()
{
	std::cout << GRAY"Destructor called"NO_COLOR << std::endl;
	return ;
}

Fixed&	Fixed::operator=(Fixed const& src)
{
	std::cout << GRAY"Copy assignment operator called"NO_COLOR << std::endl;
	this->_value = src.getRawBits();
	return (*this);
}

std::ostream& operator<<(std::ostream &os, Fixed const& t)
{
	os << t.toFloat();
	return (os);
}