/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 12:07:08 by emgul             #+#    #+#             */
/*   Updated: 2024/10/20 12:11:51 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanA
{
    public:
    	HumanA(const std::string &name, Weapon &weapon);
		~HumanA(void);
    	void    attack(void);
        void	setWeapon(const Weapon &weapon);
    private:
        std::string _name;
        Weapon &_weapon;
};

#endif
