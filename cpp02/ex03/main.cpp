#include "Point.hpp"

bool bsp(const Point a, const Point b, const Point c, const Point point);

int main(void)
{
	const Point a;
	const Point b(10, 0);
	const Point c(0, 5);
	const Point point(1, 4);

	std::cout << bsp(a, b, c, point) << std::endl;

	return (0);
}
