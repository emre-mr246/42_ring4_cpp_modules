#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#pragma once

#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap: public virtual ClapTrap
{
public:
	ScavTrap();	
	ScavTrap(const std::string &name);
	~ScavTrap();
	ScavTrap(const ScavTrap &copy);
	ScavTrap &operator=(const ScavTrap &copy);
    void guardGate();
	void changeGatekeeperMode();

protected:
	bool _gatekeeperMode;
};

#endif