#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	this->_name = "Default";
	this->_attackDamage = FragTrap::_attackDamage;
	this->_energy = ScavTrap::_energy;
	this->_health = FragTrap::_health;
	ClapTrap::_name = this->_name + "_clap_name";
	std::cout << "Default constructor called for [DiamondTrap]" << this->_name << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name): ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	this->_name = name;
	this->_attackDamage = FragTrap::_attackDamage;
	this->_energy = ScavTrap::_energy;
	this->_health = FragTrap::_health;
	std::cout << "Constructor called for [DiamondTrap]" << this->_name << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "Destructor called for [DiamondTrap]" << this->_name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src): ClapTrap(src._name + "_clap_name"), ScavTrap(src._name), FragTrap(src._name)
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
    std::cout << "My ClapTrap name is " << ClapTrap::_name << std::endl;
}