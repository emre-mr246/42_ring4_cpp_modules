/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 12:38:26 by emgul            #+#    #+#              */
/*   Updated: 2025/08/19 13:08:42 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>

class NotFoundException : public std::exception
{
  public:
	virtual const char *what() const throw()
	{
		return ("Element not found in the container");
	}
};

template <typename T>
typename T::iterator easyfind(T &container, int nbr)
{
	typename T::iterator it;

	it = std::find(container.begin(), container.end(), nbr);
	if (it == container.end())
		throw NotFoundException();
	return (it);
}

#endif