/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 12:38:29 by emgul             #+#    #+#             */
/*   Updated: 2025/07/28 12:44:46 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "B.hpp"

B::B(void)
{
    std::cout << "Default constructor called for B" << std::endl;
}

B::~B()
{
    std::cout << "Destructor called for B" << std::endl;
}

B::B(const B &src)
{
    (void)src;
    std::cout << "Copy constructor called for B" << std::endl;
}
