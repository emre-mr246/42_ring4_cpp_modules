#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#pragma once

#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap: public ClapTrap
{
public:
	ScavTrap();	
	ScavTrap(const std::string &name);
	~ScavTrap();
	ScavTrap(const ScavTrap &copy);
	ScavTrap &operator=(const ScavTrap &copy);
    void guardGate();
	void changeGatekeeperMode();

private:
	bool _gatekeeperMode;
};

#endif