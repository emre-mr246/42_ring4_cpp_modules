/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:12:33 by emgul             #+#    #+#             */
/*   Updated: 2025/01/13 10:12:34 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "Fixed.hpp"

class Point
{
public:
	Point();
	Point(const float x, const float y);
	Point(const Point &copy);
	~Point();
	Point &operator=(const Point &src);
	const Fixed &getX(void) const;
	const Fixed &getY(void) const;

private:
	const Fixed _x;
	const Fixed _y;
};

std::ostream &operator<<(std::ostream &ostream, Point const point);
