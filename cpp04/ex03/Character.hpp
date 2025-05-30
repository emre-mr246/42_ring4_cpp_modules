/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:09:51 by emgul             #+#    #+#             */
/*   Updated: 2025/01/13 10:09:53 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#pragma once

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character: public ICharacter
{
public:
	Character(void);
	Character(std::string name);
	~Character();
	Character(const Character &src);
	Character &operator=(const Character &src);
	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
	void printInventory() const;
	
private:
	std::string _name;
    AMateria *_inventory[4];
};

#endif
