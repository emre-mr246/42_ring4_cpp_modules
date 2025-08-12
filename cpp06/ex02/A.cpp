/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 12:38:29 by emgul            #+#    #+#              */
/*   Updated: 2025/08/12 19:03:43 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"

A::A(void)
{
    std::cout << "Default constructor called for A" << std::endl;
}

A::~A()
{
    std::cout << "Destructor called for A" << std::endl;
}

A::A(const A &src)
{
    (void)src;
    std::cout << "Copy constructor called for A" << std::endl;
}
