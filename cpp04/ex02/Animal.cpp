/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:10:19 by emgul             #+#    #+#             */
/*   Updated: 2025/01/13 10:10:20 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
    this->_type = "Animal";
    std::cout << "Default constructor called for " << this->_type << std::endl;
}

Animal::~Animal()
{
    std::cout << "Destructor called for " << this->_type << std::endl;
}

Animal::Animal(const Animal &src)
{
    *this = src;
    std::cout << "Copy constructor called for " << this->_type << std::endl;
}

Animal &Animal::operator=(const Animal &src)
{
    this->_type = src._type;
    std::cout << "Copy assignment operator called for " << this->_type
              << std::endl;
    return (*this);
}

void Animal::makeSound(void) const
{
    std::cout << this->_type << ": Animal class's makeSound() function called."
              << std::endl;
}
