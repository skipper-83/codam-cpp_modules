#include "Point.hpp"

static float	triangle_area(Point a, Point b, Point c)
{
	float	area;

	area = a.getX() * ((b.getY() - c.getY())) + b.getX() * (c.getY()- a.getY()) + c.getX() * (a.getY() - b.getY());
	if (area < 0)
		return (area * -0.5f);
	return (area * 0.5f);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	float	original_area;
	float	ab_area;
	float	bc_area;
	float	ac_area;

	original_area = triangle_area(a, b, c);
	ab_area = triangle_area(point, a, b);
	bc_area = triangle_area(point, b, c);
	ac_area = triangle_area(point, a, c);

	if (!ab_area || !bc_area || !ac_area)
		return (false);
	if ((ab_area + bc_area + ac_area) > original_area)
		return (false);
	return (true);
}