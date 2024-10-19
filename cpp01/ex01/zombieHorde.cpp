/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 00:26:18 by emgul             #+#    #+#             */
/*   Updated: 2024/10/20 00:38:43 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    int i;

    Zombie *horde = new Zombie[N];
	if (!horde)
	{
		std::cout << "Memory allocation failed." << std::endl;
		return (NULL);
	}
    i = 0;
    while (i < N)
    {
        horde[i].setName(name);
        i++;
    }
	return (horde);
}
