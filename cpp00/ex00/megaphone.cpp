/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 22:41:41 by emgul             #+#    #+#             */
/*   Updated: 2024/09/28 23:08:42 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int ac, char **av)
{
    char *ptr;
    int i;

    if (ac == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    i = 1;
    while (i < ac)
    {
        ptr = av[i];
        while (*ptr)
        {
            std::cout << (char)std::toupper(*ptr);
            ptr++;
        }
        i++;
    }
    std::cout << std::endl;
    return (0);
}
