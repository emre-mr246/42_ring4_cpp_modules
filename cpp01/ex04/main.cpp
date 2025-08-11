/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:52:26 by emgul             #+#    #+#             */
/*   Updated: 2024/10/21 18:13:19 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cerr << "An known error occured!" << std::endl;
        return (-1);
    }
    replace(av[1], av[2], av[3]);
    return (0);
}
