/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:09:54 by emgul             #+#    #+#             */
/*   Updated: 2025/01/13 10:09:55 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void)
{
    this->_name = "Default";
    for (int i = 0; i < 4; i++)
        this->_inventory[i] = NULL;
    std::cout << "Default constructor called for Character." << std::endl;
}

Character::Character(std::string name)
{
    this->_name = name;
    for (int i = 0; i < 4; i++)
        this->_inventory[i] = NULL;
    std::cout << "Constructor called for Character." << std::endl;
}

Character::~Character()
{
    std::cout << "Destructor called for Character." << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (this->_inventory[i])
            delete (this->_inventory[i]);
    }
}

Character::Character(const Character &src)
{
    *this = src;
    std::cout << "Copy constructor called for Character." << std::endl;
}

Character &Character::operator=(const Character &src)
{
    if (this == &src)
        return (*this);
    this->_name = src._name;
    for (int i = 0; i < 4; i++)
    {
        if (src._inventory[i])
        {
            this->_inventory[i] = (src._inventory[i])->clone();
            if (!this->_inventory[i])
                std::cerr << "Clone failed for inventory item " << i << std::endl;
        }
        else
            this->_inventory[i] = NULL;
    }
    std::cout << "Copy assignment operator called for Character." << std::endl;
    return (*this);
}

std::string const &Character::getName() const
{
    return (this->_name);
}

void Character::equip(AMateria *materia)
{
    if (!materia)
    {
        std::cout << this->_name << " attempted to equip an empty materia." << std::endl;
        return;
    }
    for (int i = 0; i < 4; ++i)
    {
        if (this->_inventory[i] == NULL)
        {
            this->_inventory[i] = materia;
            std::cout << this->_name << " successfully equipped " << materia->getType() << " in slot " << i << std::endl;
            return;
        }
    }
    std::cout << this->_name << " can't equip more than 4 Materia." << std::endl;
}

void Character::unequip(int i)
{
    if (i < 0 || i > 4)
    {
        std::cout << this->_name << ": Invalid slot index " << i << ". Slot index must be between 0 and 4." << std::endl;
        return;
    }
    if (!this->_inventory[i])
    {
        std::cout << this->_name << ": Slot " << i << " is empty! No item to unequip." << std::endl;
        return;
    }
    std::cout << this->_name << ": " << this->_inventory[i]->getType() << " unequipped from slot " << i << "." << std::endl;
    this->_inventory[i] = NULL;
}

void Character::use(int i, ICharacter &target)
{
    if (i < 0 || i > 4)
    {
        std::cout << this->_name << ": Invalid slot index " << i << ". Slot index must be between 0 and 4." << std::endl;
        return;
    }
    std::cout << this->getName() << ": Using " << this->_inventory[i]->getType()
              << " on " << target.getName() << "." << std::endl;
    this->_inventory[i]->use(target);
    std::cout << this->getName() << ": " << this->_inventory[i]->getType()
              << " has been used on " << target.getName() << "." << std::endl;
}

void Character::printInventory() const
{
    int i;

    std::cout << "== " << this->getName() << "'s Inventory ==" << std::endl;
    i = 0;
    while (i < 4)
    {
        if (this->_inventory[i])
            std::cout << "[" << i << "] " << this->_inventory[i]->getType() << std::endl;
        i++;
    }
    std::cout << "===== END ==" << std::endl;
}
