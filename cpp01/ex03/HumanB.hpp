/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 12:10:08 by emgul             #+#    #+#             */
/*   Updated: 2024/10/20 13:20:53 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanB
{
  public:
    HumanB(const std::string &name);
    ~HumanB(void);
    void attack(void);
    void setWeapon(Weapon &weapon);

  private:
    std::string _name;
    Weapon *_weapon;
};

#endif
