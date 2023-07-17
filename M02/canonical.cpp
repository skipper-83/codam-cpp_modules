#include "canonical.hpp"

int	Canon::getFoo()
{
	return (this->_foo);
}

void	Canon::setFoo(int new_foo)
{
	this->_foo = new_foo;
}

Canon::Canon()
{
	std::cout << "Standard constructor" << std::endl;
}

Canon::Canon(Canon const& src)
{
	std::cout << "Copy constructor" << std::endl;
	// *this = src;
}

Canon&	Canon::operator=(Canon const& src)
{
	std::cout << "Assignment constructor" << std::endl;
	// *this = src;
	return *this;
}

Canon::~Canon()
{
	std::cout << "Destructor called" << std::endl;
}