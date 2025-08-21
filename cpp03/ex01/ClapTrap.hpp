/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:12:09 by emgul            #+#    #+#              */
/*   Updated: 2025/08/20 14:25:32 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#pragma once

#include <iostream>

class ClapTrap
{
  public:
	ClapTrap();
	ClapTrap(const std::string &name);
	~ClapTrap();
	ClapTrap(const ClapTrap &src);
	ClapTrap &operator=(const ClapTrap &src);
	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void printStats();

  protected:
	std::string _name;
	unsigned int _health;
	unsigned int _energy;
	unsigned int _attackDamage;
};

#endif
