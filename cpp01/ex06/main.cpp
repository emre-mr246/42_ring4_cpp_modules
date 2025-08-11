/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:13:24 by emgul             #+#    #+#             */
/*   Updated: 2025/01/13 10:13:26 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vessel.hpp"

int main(int ac, char **av)
{
    Vessel ves;

    if (ac != 2)
    {
        std::cout << "[ Probably complaining about insignificant problems ]"
                  << std::endl;
        return (0);
    }
    ves.complain(av[1]);
    return (0);
}
