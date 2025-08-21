/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:09:55 by emgul            #+#    #+#              */
/*   Updated: 2025/08/20 14:25:33 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void) : _type("none")
{
	std::cout << "Default constructor called for AMateria." << std::endl;
}

AMateria::AMateria(const std::string &type) : _type(type)
{
	std::cout << "Constructor called for AMateria." << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "Destructor called for AMateria." << std::endl;
}

AMateria::AMateria(const AMateria &src)
{
	std::cout << "Copy constructor called for AMateria." << std::endl;
	*this = src;
}

AMateria &AMateria::operator=(const AMateria &src)
{
	this->_type = src._type;
	std::cout << "Copy assignment operator called for AMateria." << std::endl;
	return (*this);
}

void AMateria::use(ICharacter &target)
{
	std::cout << "AMateria used on " << target.getName() << "." << std::endl;
}

std::string const &AMateria::getType() const
{
	return (this->_type);
}
