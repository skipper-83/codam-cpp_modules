#ifndef POINT_HPP
# define POINT_HPP
# include <iostream>
# include "Fixed.hpp"

class Point
{
	public:
		Point(void);
		Point(float const x, float const y);
		Point(Point const& src);
		~Point(void);

		Point&	operator=(Point const& src);
		float	getX(void) const;
		float	getY(void) const;

	private:
		Fixed const	_x;
		Fixed const _y;
};

std::ostream&	operator<<(std::ostream& os, Point const& t);

#endif