/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:10:26 by emgul            #+#    #+#              */
/*   Updated: 2025/08/20 14:25:32 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	std::cout << "Default constructor called for " << this->_type << std::endl;
	this->_type = "WrongCat";
	this->_brain = new Brain();
	if (!this->_brain)
	{
		std::cerr << "Brain allocation failed for WrongCat!" << std::endl;
		return;
	}
}

WrongCat::~WrongCat()
{
	if (this->_brain)
		delete (this->_brain);
	std::cout << "Destructor called for " << this->_type << std::endl;
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal()
{
	*this = src;
	std::cout << "Copy constructor called for " << this->_type << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &src)
{
	this->_type = src._type;
	std::cout << "Copy assignment operator called for " << this->_type
	          << std::endl;
	return (*this);
}

void WrongCat::makeSound(void) const
{
	std::cout << this->_type << ": ** Meoaowwggogwasdfghw! **" << std::endl;
}
