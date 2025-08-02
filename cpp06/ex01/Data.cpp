/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 12:38:29 by emgul             #+#    #+#             */
/*   Updated: 2025/07/28 12:44:46 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(void)
{
}

Data::~Data()
{
}

Data::Data(const Data &src)
{
    (void)src;
}

Data &Data::operator=(const Data &src)
{
    if (this == &src)
        return (*this);
    return (*this);
}
