/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 13:27:23 by emgul            #+#    #+#              */
/*   Updated: 2025/08/20 14:25:34 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);

    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.top() << std::endl << std::endl;

    std::cout << mstack.size() << std::endl;
    mstack.push(0);
    std::cout << mstack.size() << std::endl << std::endl;

    MutantStack<int>::iterator it_begin = mstack.begin();
    MutantStack<int>::iterator it_end = mstack.end();
    while (it_begin != it_end)
    {
        std::cout << *it_begin << std::endl;
        it_begin++;
    }
    std::cout << std::endl;

    std::stack<int> s(mstack);
    s.push(42);
    std::cout << s.top() << std::endl;
    s.pop();
    std::cout << s.size() << std::endl;

    return (0);
}