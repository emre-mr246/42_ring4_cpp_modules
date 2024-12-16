#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap()
{
	std::cout << "Constructor called for [Empty DiamondTrap]" << "Frank" << std::endl;
	this->_name = "Frank_clap_name";
	this->_attackDamage = 0;
	this->_energy = 1;
	this->_health = 1;
}

DiamondTrap::DiamondTrap(const std::string &name): ClapTrap(name + "_clap_name")
{
	std::cout << "Constructor called for [DiamondTrap]" << name << std::endl;
	this->_name = name;
	this->_attackDamage = FragTrap::_attackDamage;
	this->_energy = ScavTrap::_energy;
	this->_health = FragTrap::_health;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "Destructor called for [DiamondTrap]" << this->_name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src): ClapTrap(src), ScavTrap(src), FragTrap(src)
{
	this->_name = "Clone";
	this->_attackDamage = 0;
	this->_energy = 10;
	this->_health = 10;
	std::cout << "Copy constructor called for [DiamondTrap]" << src._name << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_name = src._name;
	this->_attackDamage = src._attackDamage;
	this->_energy = src._energy;
	this->_health = src._health;
	return (*this);
}

void DiamondTrap::whoAmI()
{
    std::cout << "I am " << this->_name << std::endl;
}
