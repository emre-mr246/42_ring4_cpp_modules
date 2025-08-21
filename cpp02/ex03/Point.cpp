/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:12:35 by emgul            #+#    #+#              */
/*   Updated: 2025/08/20 14:25:35 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
}

Point::Point(const float x, const float y) : _x(x), _y(y)
{
}

Point::Point(const Point &copy) : _x(copy.getX()), _y(copy.getY())
{
}

Point::~Point()
{
}

Point &Point::operator=(const Point &src)
{
	if (this == &src)
		return (*this);
	return (*this);
}

const Fixed &Point::getX(void) const
{
	return (this->_x);
}

const Fixed &Point::getY(void) const
{
	return (this->_y);
}

std::ostream &operator<<(std::ostream &ostream, Point const point)
{
	ostream << "_x: " << point.getX() << " / _y: " << point.getY() << std::endl;
	return (ostream);
}
