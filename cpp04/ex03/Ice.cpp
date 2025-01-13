/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:09:47 by emgul             #+#    #+#             */
/*   Updated: 2025/01/13 10:09:48 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void)
{
    this->_type = "ice";
    std::cout << "Default constructor called for Ice." << std::endl;
}

Ice::~Ice()
{
    std::cout << "Destructor called for Ice." << std::endl;
}

Ice::Ice(const Ice &src): AMateria(src)
{
    *this = src;
    std::cout << "Copy constructor called for Ice." << std::endl;
}

Ice &Ice::operator=(const Ice &src)
{
	std::cout << "Copy assignment operator called for Ice." << std::endl;
	// if (this == &src)
	// 	return (*this);
	return (*this);
}

void Ice::use(ICharacter &src)
{
    std::cout << "* shoots an ice bolt at " << src.getName() << " *" << std::endl;
}

AMateria	*Ice::clone(void) const
{
    AMateria *clone = new Ice(*this);
    if (!clone)
    {
        return (NULL);
    }
    return (clone);
}

std::string const & Ice::getType() const
{
    return (this->_type);
}
