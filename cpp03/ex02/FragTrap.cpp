#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
	std::cout << "Constructor called for [Empty FragTrap]" << "Frank" << std::endl;
	this->_name = "Frank";
	this->_attackDamage = 0;
	this->_energy = 1;
	this->_health = 1;
}

FragTrap::FragTrap(const std::string &name): ClapTrap(name)
{
	std::cout << "Constructor called for [FragTrap]" << name << std::endl;
	this->_name = name;
	this->_attackDamage = 30;
	this->_energy = 100;
	this->_health = 100;
}

FragTrap::~FragTrap()
{
	std::cout << "Destructor called for [FragTrap]" << this->_name << std::endl;
}

FragTrap::FragTrap(const FragTrap &src): ClapTrap(src)
{
	this->_name = "Clone";
	this->_attackDamage = 0;
	this->_energy = 10;
	this->_health = 10;
	std::cout << "Copy constructor called for [FragTrap]" << src._name << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_name = src._name;
	this->_attackDamage = src._attackDamage;
	this->_energy = src._energy;
	this->_health = src._health;
	return (*this);
}

void FragTrap::highFivesGuys(void)
{
    if (this->_health > 0 && this->_energy > 0)
        std::cout << "[FragTrap] *High five* for guarding the gate like a true hero!" << std::endl;
    else
        std::cout << "Not enough energy or FragTrap is dead." << std::endl;
    return ;
}

