/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 12:38:23 by emgul            #+#    #+#              */
/*   Updated: 2025/08/20 14:25:34 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template <typename T>
void print(T &element)
{
	std::cout << element << std::endl;
}

int main(void)
{
	double doubleTab[] = {4.0, 2.0};
	iter(doubleTab, 2, print);

	std::string strTab[] = {"Hi", "there!"};
	iter(strTab, 2, print);

	int intTab[] = {42, 246};
	iter(intTab, 2, print);

	return (0);
}
