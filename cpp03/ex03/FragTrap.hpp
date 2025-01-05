#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#pragma once

#include "ClapTrap.hpp"
#include <iostream>

class FragTrap: virtual public ClapTrap
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
