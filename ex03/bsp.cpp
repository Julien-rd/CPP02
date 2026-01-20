#include "Point.hpp"

bool	not_a_triangle(Point a, Point b, Point c)
{
	if ((a.get_x().toFloat() == b.get_x().toFloat()
			&& a.get_y().toFloat() == b.get_y().toFloat())
		|| (a.get_x().toFloat() == c.get_x().toFloat()
			&& a.get_y().toFloat() == c.get_y().toFloat())
		|| (b.get_x().toFloat() == c.get_x().toFloat()
			&& b.get_y().toFloat() == c.get_y().toFloat()))
	{
		std::cout << "not a triangle!" << std::endl;
		return (true);
	}
	return (false);
}

bool	is_on_edge(Point a, Point b, Point c, Point point)
{
	float	vector_x;
	float	vector_y;
	float factor;

	vector_x = std::abs(a.get_x().toFloat() - b.get_x().toFloat());
	vector_y = std::abs(a.get_y().toFloat() - b.get_y().toFloat());
	factor = point.get_x().toFloat() / vector_x; 
	if (vector_y * factor == point.get_y().toFloat())
		return (true);
	vector_x = std::abs(b.get_x().toFloat() - c.get_x().toFloat());
	vector_y = std::abs(b.get_y().toFloat() - c.get_y().toFloat());
	factor = point.get_x().toFloat() / vector_x; 
	if (vector_y * factor == point.get_y().toFloat())
		return (true);
	vector_x = std::abs(c.get_x().toFloat() - a.get_x().toFloat());
	vector_y = std::abs(c.get_y().toFloat() - a.get_y().toFloat());
	factor = point.get_x().toFloat() / vector_x; 
	if (vector_y * factor == point.get_y().toFloat())
		return (true);
	return (false);
}

float	cal_area(Point a, Point b, Point c)
{
	float	area;

	area = 0.5 * std::abs(a.get_x() * (b.get_y() - c.get_y()) + b.get_x()
			* (c.get_y() - a.get_y()) + c.get_x() * (a.get_y() - b.get_y()));
	return (area);
}

bool	bsp(Point a, Point b, Point c, Point point)
{
	float	main_area;
	float	sum_area;

	if (not_a_triangle(a, b, c))
		return (false);
	main_area = cal_area(a, b, c);
	sum_area = cal_area(a, b, point) + cal_area(a, point, c) + cal_area(point,
			b, c);
	if (main_area == sum_area && !is_on_edge(a, b, c, point))
	{
		std::cout << "point is inside !" << std::endl;
		return (true);
	}
	std::cout << "point is outside !" << std::endl;
	return (false);
}
