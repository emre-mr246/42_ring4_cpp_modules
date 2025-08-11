/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:11:05 by emgul             #+#    #+#             */
/*   Updated: 2025/01/13 10:11:06 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
    this->_type = "Dog";
    std::cout << "Default constructor called for " << this->_type << std::endl;
}

Dog::~Dog()
{
    std::cout << "Destructor called for " << this->_type << std::endl;
}

Dog::Dog(const Dog &src) : Animal()
{
    this->_type = src._type;
    std::cout << "Copy constructor called for " << src._type << std::endl;
}

Dog &Dog::operator=(const Dog &src)
{
    if (this == &src)
    {
        return (*this);
    }
    this->_type = src._type;
    std::cout << "Copy assignment operator called for " << this->_type
              << std::endl;
    return (*this);
}

void Dog::makeSound(void) const
{
    std::cout << this->_type << ": ** Bark! **" << std::endl;
}
