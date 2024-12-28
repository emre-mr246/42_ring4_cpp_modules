#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
	this->_health = 100;
	this->_energy = 50;
	this->_attackDamage = 30;
	this->_gatekeeperMode = false;
	std::cout << "Constructor called for [ScavTrap]" << this->_name << std::endl;
}

ScavTrap::ScavTrap(const std::string &name): ClapTrap(name)
{
	this->_health = 100;
	this->_energy = 50;
	this->_attackDamage = 30;
	this->_gatekeeperMode = false;
	std::cout << "Constructor called for [ScavTrap]" << name << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Destructor called for [ScavTrap]" << this->_name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src): ClapTrap(src._name)
{
	*this = src;
	std::cout << "Copy constructor called for [ScavTrap]" << this->_name << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &src)
{
	this->_name = src._name;
	this->_energy = src._energy;
	this->_health = src._health;
	this->_attackDamage = src._attackDamage;
	this->_gatekeeperMode = src._gatekeeperMode;
	std::cout << "Copy assignment operator called for [ScavTrap]" << src._name << std::endl;
	return (*this);
}

void ScavTrap::attack(const std::string& target)
{
	if (this->_energy > 0)
	{
		std::cout << "[ScavTrap]" << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energy--;
	}
	else
		std::cout << "Not enough energy!" << std::endl;
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
