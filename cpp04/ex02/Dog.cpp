/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:10:10 by emgul             #+#    #+#             */
/*   Updated: 2025/01/13 10:10:11 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	this->_type = "Dog";
	this->_brain = new Brain();
	if (!this->_brain)
	{
		std::cerr << "Brain allocation failed for Dog!" << std::endl;
		return;
	}
	std::cout << "Default constructor called for " << this->_type << std::endl;
}

Dog::~Dog()
{
	if (this->_brain)
		delete (this->_brain);
	std::cout << "Destructor called for " << this->_type << std::endl;
}

Dog::Dog(const Dog &src) : Animal()
{
	this->_type = src._type;
	if (src._brain)
		this->_brain = new Brain(*src._brain);
	else
		this->_brain = NULL;
	std::cout << "Copy constructor called for " << src._type << std::endl;
}

Dog &Dog::operator=(const Dog &src)
{
	if (this == &src)
	{
		return (*this);
	}
	this->_type = src._type;
	if (this->_brain)
		delete (this->_brain);
	this->_brain = new Brain(*src._brain);
	std::cout << "Copy assignment operator called for " << this->_type << std::endl;
	return (*this);
}

void Dog::makeSound(void) const
{
	std::cout << this->_type << ": ** Bark! **" << std::endl;
}

void Dog::newIdea(unsigned int i, std::string idea)
{
	this->_brain->setIdea(i, idea);
}

const std::string Dog::getIdea(unsigned int i) const
{
	return (this->_brain->getIdea(i));
}
