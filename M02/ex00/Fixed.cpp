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

Fixed::Fixed(void)
{
	this->_value = 0;
	std::cout << GRAY"Default constructor called"NO_COLOR << std::endl;
	return ;
}

Fixed::Fixed(Fixed const& src)
{
	 std::cout << GRAY"Copy constructor called"NO_COLOR << std::endl;
	 this->_value = src.getRawBits();
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