/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 12:38:29 by emgul             #+#    #+#             */
/*   Updated: 2025/07/28 12:44:46 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void)
{
	std::cout << "Default constructor called for Serializer" << std::endl;
}

Serializer::~Serializer()
{
	std::cout << "Destructor called for Serializer" << std::endl;
}

Serializer::Serializer(const Serializer &src)
{
    (void)src;
    std::cout << "Copy constructor called for Serializer" << std::endl;
}

Serializer &Serializer::operator=(const Serializer &src)
{
    if (this == &src)
        return (*this);
    std::cout << "Copy assignment operator called for Serializer" << std::endl;
    return (*this);
}

uintptr_t Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}
