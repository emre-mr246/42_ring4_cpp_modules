/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:12:37 by emgul             #+#    #+#             */
/*   Updated: 2025/01/13 10:12:38 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
