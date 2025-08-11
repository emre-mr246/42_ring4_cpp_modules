/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:11:32 by emgul             #+#    #+#             */
/*   Updated: 2025/01/13 10:11:33 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#pragma once

#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : virtual public ClapTrap
{
  public:
    FragTrap();
    FragTrap(const std::string &name);
    ~FragTrap();
    FragTrap(const FragTrap &copy);
    FragTrap &operator=(const FragTrap &copy);
    void highFivesGuys(void);
    void beRepaired(unsigned int amount);
};

#endif
