#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
	this->_health = 100;
	this->_energy = 100;
	this->_attackDamage = 30;
	std::cout << "Constructor called for [FragTrap]" << this->_name << std::endl;
}

FragTrap::FragTrap(const std::string &name): ClapTrap(name)
{
	this->_health = 100;
	this->_energy = 100;
	this->_attackDamage = 30;
	std::cout << "Constructor called for [FragTrap]" << name << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "Destructor called for [FragTrap]" << this->_name << std::endl;
}

FragTrap::FragTrap(const FragTrap &src): ClapTrap(src._name)
{
	this->operator=(src);
	std::cout << "Copy constructor called for [FragTrap]" << src._name << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &src)
{
	this->_name = src._name;
	this->_energy = src._energy;
	this->_health = src._health;
	this->_attackDamage = src._attackDamage;
	std::cout << "Copy assignment operator called for [FragTrap]" << src._name << std::endl;
	return (*this);
}

void FragTrap::beRepaired(unsigned int amount)
{
	if (this->_energy > 0)
	{
		if (this->_health == 0)
			std::cout << this->_name <<  " is rebooting itself!" << std::endl;
		else
			std::cout << this->_name << " is repairing itself!" << std::endl;
		if (this->_health + amount > 100)
			this->_health = 100;
		else
			this->_health += amount;
		this->_energy--;
	}
	else
		std::cout << "Not enough energy!" << std::endl;
}

// void FragTrap::attack(const std::string& target)
// {
// 	if (this->_energy > 0)
// 	{
// 		std::cout << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage." << std::endl;
// 		this->_energy--;
// 	}
// 	else
// 		std::cout << "Not enough energy!" << std::endl;
// }

void FragTrap::highFivesGuys(void)
{
    if (this->_health > 0 && this->_energy > 0)
        std::cout << this->_name << " *High five* for guarding the gate like a true hero!" << std::endl;
    else
        std::cout << "Not enough energy or FragTrap is dead." << std::endl;
    return ;
}

