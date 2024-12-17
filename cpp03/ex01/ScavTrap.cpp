#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "Constructor called for [Empty ScavTrap]" << "Frank" << std::endl;
	this->_name = "Frank";
	this->_attackDamage = 0;
	this->_energy = 1;
	this->_health = 1;
	this->_gatekeeperMode = false;
}

ScavTrap::ScavTrap(const std::string &name): ClapTrap(name)
{
	std::cout << "Constructor called for [ScavTrap]" << name << std::endl;
	this->_name = name;
	this->_attackDamage = 20;
	this->_energy = 50;
	this->_health = 100;
	this->_gatekeeperMode = false;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Destructor called for [ScavTrap]" << this->_name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src): ClapTrap(src._name + "_clone_base")
{
	this->_name = src._name + "_clone";
	this->_attackDamage = 20;
	this->_energy = 50;
	this->_health = 100;
	std::cout << "Copy constructor called for [ScavTrap]" << this->_name << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &src)
{
	std::cout << "Copy assignment operator called for [ScavTrap]" << src._name + "_assigned"<< std::endl;
	ClapTrap::operator=(src);
	return (*this);
}

void ScavTrap::guardGate()
{
	if (this->_health == 0)
 	{
        std::cout << "[ScavTrap]" << this->_name << " has no health left! It's time for a repair!" << std::endl;
		return ;
    }
	else if (this->_energy == 0)
	{
        std::cout << "[ScavTrap]" << this->_name << " is out of energy! It needs a recharge!" << std::endl;
		return ;
    }
	if (this->_gatekeeperMode == true)
		std::cout << "[ScavTrap]" << this->_name << " is on a heroic mission, guarding the sacred gate!" << std::endl;
	else
	{
		std::cout << "[ScavTrap]" << this->_name << " is recharging with a refreshing oil cocktail in the robot cafe." << std::endl;
		this->_energy++;
	}
}

void ScavTrap::changeGatekeeperMode()
{
	this->_gatekeeperMode = !this->_gatekeeperMode;
	if (_gatekeeperMode)
		std::cout << "[ScavTrap]" << this->_name << " - Gatekeeper mode activated." << std::endl;
	else
		std::cout << "[ScavTrap]" << this->_name << " - Gatekeeper mode disabled." << std::endl;
}