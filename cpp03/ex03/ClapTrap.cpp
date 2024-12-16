#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "Constructor called for [Empty ClapTrap]" << "Frank" << std::endl;
	this->_name = "Frank";
	this->_attackDamage = 0;
	this->_energy = 1;
	this->_health = 1;
}

ClapTrap::ClapTrap(const std::string &name)
{
	std::cout << "Constructor called for [ClapTrap]" << name << std::endl;
	this->_name = name;
	this->_attackDamage = 0;
	this->_energy = 10;
	this->_health = 10;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called for [ClapTrap]" << this->_name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	this->_name = "Clone";
	this->_attackDamage = 0;
	this->_energy = 10;
	this->_health = 10;
	std::cout << "Copy constructor called for [ClapTrap]" << src._name << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_name = src._name;
	this->_attackDamage = src._attackDamage;
	this->_energy = src._energy;
	this->_health = src._health;
	return (*this);
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_energy > 0)
	{
		std::cout << "[ClapTrap]" << this->_name << " attacks [ClapTrap]" << target << ", causing " << this->_attackDamage << " points of damage." << std::endl;
		this->_energy--;
	}
	else
		std::cout << "Not enough energy!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_health >= amount)
		this->_health -= amount;
	else
		this->_health = 0;
	std::cout << "*** -DAMAGE- *** " << this->_name << " takes " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energy > 0)
	{
		if (this->_health == 0)
			std::cout << "[ClapTrap]" << this->_name <<  " is rebooting itself!" << std::endl;
		else
			std::cout << "[ClapTrap]" << this->_name << " is repairing itself!" << std::endl;
		if (this->_health + amount > 10)
			this->_health = 10;
		else
			this->_health += amount;
		this->_energy--;
	}
	else
		std::cout << "Not enough energy!" << std::endl;
}
