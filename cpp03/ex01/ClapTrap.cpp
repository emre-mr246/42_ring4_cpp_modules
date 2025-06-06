/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:12:12 by emgul             #+#    #+#             */
/*   Updated: 2025/01/13 10:12:13 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	this->_name = "Default";
	this->_health = 100;
	this->_energy = 50;
	this->_attackDamage = 20;
	std::cout << "Default constructor called for [ClapTrap]" << this->_name << std::endl;
}

ClapTrap::ClapTrap(const std::string &name)
{
	this->_name = name;
	this->_health = 100;
	this->_energy = 50;
	this->_attackDamage = 20;
	std::cout << "Constructor called for [ClapTrap]" << this->_name << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called for [ClapTrap]" << this->_name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	*this = src;
	std::cout << "Copy constructor called for [ClapTrap]" << this->_name << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &src)
{
	this->_name = src._name;
	this->_energy = src._energy;
	this->_health = src._health;
	this->_attackDamage = src._attackDamage;
	std::cout << "Copy assignment operator called for [ClapTrap]" << this->_name << std::endl;
	return (*this);
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_energy > 0)
	{
		std::cout << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage." << std::endl;
		this->_energy--;
	}
	else
		std::cout << "Not enough energy!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_health >= amount)
		this->_health -= amount;
	else
		this->_health = 0;
	std::cout << "*** -DAMAGE- *** " << this->_name << " takes " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energy > 0)
	{
		if (this->_health == 0)
			std::cout << this->_name <<  " is rebooting itself!" << std::endl;
		else
			std::cout << this->_name << " is repairing itself!" << std::endl;
		if (this->_health + amount > 100)
			this->_health = 100;
		else
			this->_health += amount;
		this->_energy--;
	}
	else
		std::cout << "Not enough energy!" << std::endl;
}

void ClapTrap::printStats()
{
	std::cout << this->_name << "[H:" << this->_health << "/E:"<< this->_energy << "/D:" << this->_attackDamage << "]" << std::endl;
}
