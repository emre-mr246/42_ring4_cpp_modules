/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 12:38:26 by emgul            #+#    #+#              */
/*   Updated: 2025/08/12 19:03:34 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>

template <typename T> void iter(T *array, size_t length, void (*func)(T &))
{
    unsigned int i;

    i = 0;
    while (i < length)
    {
        func(array[i]);
        i++;
    }
}

#endif