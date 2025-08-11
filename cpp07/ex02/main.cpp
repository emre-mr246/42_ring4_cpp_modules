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

#include "Array.hpp"
#include <iostream>

int main(int, char **)
{
    Array<int> intArray(5);
    int i;

    i = 0;
    while (i < 5)
    {
        intArray[i] = i;
        i++;
    }
    intArray.printArray();

    Array<int> intArrayCopy(intArray);
    intArrayCopy.printArray();

    intArrayCopy[0] = 42;
    intArrayCopy.printArray();
    intArray.printArray();

    return (0);
}