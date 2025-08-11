/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 12:00:32 by emgul             #+#    #+#             */
/*   Updated: 2024/10/20 12:07:04 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon
{
  public:
    Weapon(const std::string &type);
    ~Weapon(void);
    const std::string &getType(void);
    void setType(const std::string &name);

  private:
    std::string _type;
};

#endif