/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:11:38 by emgul             #+#    #+#             */
/*   Updated: 2025/01/13 10:11:39 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap("Default_clap_name"), ScavTrap(), FragTrap()
{
	this->_name = "Default";
	this->_health = FragTrap::_health;
	this->_energy = ScavTrap::_energy;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << "Default constructor called for [DiamondTrap]" << this->_name << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name): ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	this->_name = name;
	this->_health = FragTrap::_health;
	this->_energy = ScavTrap::_energy;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << "Constructor called for [DiamondTrap]" << this->_name << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "Destructor called for [DiamondTrap]" << this->_name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src): ClapTrap(src._name + "_clap_name"), ScavTrap(src._name), FragTrap(src._name)
{
	*this = src;
	std::cout << "Copy constructor called for [DiamondTrap]" << this->_name << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &src)
{
	this->_name = src._name;
	this->_energy = src._energy;
	this->_health = src._health;
	this->_attackDamage = src._attackDamage;
	this->_gatekeeperMode = src._gatekeeperMode;
	std::cout << "Copy assignment operator called for [ScavTrap]" << src._name << std::endl;
	return (*this);
}

void DiamondTrap::whoAmI()
{
    std::cout << "I am " << this->_name << std::endl;
    std::cout << "My ClapTrap name is " << ClapTrap::_name << std::endl;
}

void DiamondTrap::printStats()
{
	std::cout << this->_name << "[H:" << this->_health << "/E:"<< this->_energy << "/D:" << this->_attackDamage << "]" << std::endl;
}
