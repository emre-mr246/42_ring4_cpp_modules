/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 00:24:02 by emgul             #+#    #+#             */
/*   Updated: 2024/10/20 00:41:42 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    int horde_size;
    int i;

    horde_size = 5;
    Zombie *horde = zombieHorde(horde_size, "Emre");
    i = 0;
    while (i < horde_size)
    {
        horde[i].announce();
        i++;
    }
    delete[] horde;
    return (0);
}
