#include "Fixed.hpp"
#include "Point.hpp"
#define BOLD "\033[1m"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int	main(void)
{
	Point a(0.5,5.5);
	Point b(4.5,5.5);
	Point c(3.5,-4.5);
	Point inside_point(2.22, 2.22);
	Point outside_point(7, 7);
	Point vertex_point (4.5, 5.5);
	Point line_point (2.5, 5.5);
	Point test;
	test = line_point;

	std::cout << "Values of point created with copy assignment operator: " << test << std::endl;

	std::cout << std::endl << BOLD"Triangle: A" << a << " B" << b << " C" << c << NO_COLOR << std::endl;
	std::cout << std::boolalpha << std::fixed << std::setw(6) << std::endl;
	std::cout << "Inside point:\t" << inside_point << " -> " << bsp(a, b, c, inside_point) << std::endl;
	std::cout << "Outside point:\t" << outside_point << " -> " << bsp(a, b, c, outside_point) << std::endl;
	std::cout << "Vertex point:\t" << vertex_point << " -> " << bsp(a, b, c, vertex_point) << std::endl;
	std::cout << "Point on line:\t" << line_point << " -> " << bsp(a, b, c, line_point) << std::endl;
	return 0;
}