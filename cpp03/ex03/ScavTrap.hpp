/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:11:24 by emgul             #+#    #+#             */
/*   Updated: 2025/01/13 10:11:25 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#pragma once

#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap : virtual public ClapTrap
{
  public:
    ScavTrap();
    ScavTrap(const std::string &name);
    ~ScavTrap();
    ScavTrap(const ScavTrap &copy);
    ScavTrap &operator=(const ScavTrap &copy);
    void attack(const std::string &target);
    void guardGate();
    void changeGatekeeperMode();

  protected:
    unsigned int _energy;
    bool _gatekeeperMode;
};

#endif
