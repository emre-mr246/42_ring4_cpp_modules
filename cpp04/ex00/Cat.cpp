/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:11:03 by emgul             #+#    #+#             */
/*   Updated: 2025/01/13 10:11:04 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
    this->_type = "Cat";
    std::cout << "Default constructor called for " << this->_type << std::endl;
}

Cat::~Cat()
{
    std::cout << "Destructor called for " << this->_type << std::endl;
}

Cat::Cat(const Cat &src) : Animal()
{
    this->_type = src._type;
    std::cout << "Copy constructor called for " << src._type << std::endl;
}

Cat &Cat::operator=(const Cat &src)
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

void Cat::makeSound(void) const
{
    std::cout << this->_type << ": ** Meow! **" << std::endl;
}
