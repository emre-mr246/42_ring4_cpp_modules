/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 18:51:43 by emgul            #+#    #+#              */
/*   Updated: 2025/08/20 14:25:34 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
    Span sp;
    std::vector<int> v;
    int i;

    i = 0;
    while (i < 20000)
    {
        v.push_back(i * 5);
        i++;
    }
    sp = Span(42000);
    try
    {
        sp.addNumber(v.begin(), v.end());
        std::cout << "shortest distance: " << sp.shortestSpan() << std::endl;
        std::cout << "longest distance: " << sp.longestSpan() << std::endl;
    } catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}