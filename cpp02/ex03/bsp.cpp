/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:12:48 by emgul            #+#    #+#              */
/*   Updated: 2025/08/20 14:25:35 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static float area(const Point p1, const Point p2, const Point p3)
{
	float area;

	area =
	    ((p1.getX().toFloat() * (p2.getY().toFloat() - p3.getY().toFloat())) +
	     (p2.getX().toFloat() * (p3.getY().toFloat() - p1.getY().toFloat())) +
	     (p3.getX().toFloat() * (p1.getY().toFloat() - p2.getY().toFloat()))) /
	    2;
	if (area >= 0)
		return (area);
	else
		return (area * -1);
}

double ftFabs(double x)
{
	if (x < 0)
		return (-x);
	else
		return (x);
}

bool bsp(const Point a, const Point b, const Point c, const Point point)
{
	float d0, d1, d2, d3;
	const float epsilon = 1e-6;

	d0 = area(a, b, c);
	d1 = area(point, a, b);
	d2 = area(point, b, c);
	d3 = area(point, a, c);

	if (d1 < epsilon || d2 < epsilon || d3 < epsilon)
		return (false);
	else if (ftFabs(d1 + d2 + d3 - d0) < epsilon)
		return (true);
	else
		return (false);
}
