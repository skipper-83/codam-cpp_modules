#include "Point.hpp"

Point::Point() : _x(Fixed(0.0f)), _y(Fixed(0.0f)) 
{
	// std::cout <<  GRAY<<"Point default constructor called"NO_COLOR << std::endl;
	return ;
}

Point::Point(Point const&src) : _x(Fixed(src._x)), _y(Fixed(src._y))
{
	// std::cout <<  GRAY<<"Point copy constructor called"NO_COLOR << std::endl;
	return ;
}

Point::Point(float const x, float const y) : _x(Fixed(x)), _y(Fixed(y))
{
	// std::cout <<  GRAY<<"Point float constructor called"NO_COLOR << std::endl;
	return ;
}

Point::~Point() 
{
	// std::cout <<  GRAY<<"Point destructor called"NO_COLOR << std::endl;
	return ;
}

Point &Point::operator=(Point const &src)
{
	std::cout << "Assignment operator can only return a point set to (0,0) as setting the constant member variables is impossible from this function" << std::endl;
	return (*this);
}

float Point::getX(void) const
{
	return (this->_x.toFloat());
}

float	Point::getY(void) const
{
	return (this->_y.toFloat());
}

std::ostream&	operator<<(std::ostream& os, Point const& t)
{
	os << "(" << t.getX() << "," << t.getY() << ")";
	return (os);
}
