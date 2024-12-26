#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#pragma once

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

#include <iostream>

class DiamondTrap: public ScavTrap, public FragTrap
{
public:
	DiamondTrap();	
	DiamondTrap(const std::string &name);
	~DiamondTrap();
	DiamondTrap(const DiamondTrap &copy);
	DiamondTrap &operator=(const DiamondTrap &copy);
    void whoAmI();
	void printStats();

private:
    std::string _name;
};

#endif