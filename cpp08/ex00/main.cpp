/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 12:38:23 by emgul             #+#    #+#             */
/*   Updated: 2025/07/28 12:38:23 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v;
    int i;

    i = 0;
    while (i < 10)
    {
        v.push_back(i);
        i++;
    }

    try
    {
        std::cout << *easyfind(v, 3) << std::endl;
        std::cout << *easyfind(v, 42) << std::endl;
        std::cout << *easyfind(v, 246) << std::endl;
    } catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return (0);
}
