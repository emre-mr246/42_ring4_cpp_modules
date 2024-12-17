#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	std::cout << "Constructor called for [Empty DiamondTrap]" << "Frank" << std::endl;
	this->_name = "Frank";
	this->_attackDamage = 0;
	this->_energy = 1;
	this->_health = 1;
}

DiamondTrap::DiamondTrap(const std::string &name): ClapTrap(name), ScavTrap(name), FragTrap(name)
{
	std::cout << "Constructor called for [DiamondTrap]" << name << std::endl;
	this->_name = ClapTrap::_name + "_clap_name";
	this->_attackDamage = FragTrap::_attackDamage;
	this->_energy = ScavTrap::_energy;
	this->_health = FragTrap::_health;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "Destructor called for [DiamondTrap]" << this->_name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src): ClapTrap(src._name + "_clone_base"), ScavTrap(src._name + "_clone_base"), FragTrap(src._name + "_clone_base")
{
	this->_name = src._name;
	this->_attackDamage = FragTrap::_attackDamage;
	this->_energy = ScavTrap::_energy;
	this->_health = FragTrap::_health;
	std::cout << "Copy constructor called for [DiamondTrap]" << this->_name << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &src)
{
	std::cout << "Assignment operator for DiamondTrap called." << std::endl;
	ScavTrap::operator=(src);
	return (*this);
}

void DiamondTrap::whoAmI()
{
    std::cout << "I am " << this->_name << std::endl;
}
