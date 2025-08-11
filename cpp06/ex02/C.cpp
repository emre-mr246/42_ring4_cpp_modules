/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 12:38:29 by emgul             #+#    #+#             */
/*   Updated: 2025/07/28 12:44:46 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "C.hpp"

C::C(void)
{
    std::cout << "Default constructor called for C" << std::endl;
}

C::~C()
{
    std::cout << "Destructor called for C" << std::endl;
}

C::C(const C &src)
{
    (void)src;
    std::cout << "Copy constructor called for C" << std::endl;
}
