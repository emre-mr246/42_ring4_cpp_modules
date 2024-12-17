#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
	std::cout << "Constructor called for [Empty FragTrap]" << "Frank" << std::endl;
}

FragTrap::FragTrap(const std::string &name): ClapTrap(name)
{
	std::cout << "Constructor called for [FragTrap]" << name << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "Destructor called for [FragTrap]" << this->_name << std::endl;
}

FragTrap::FragTrap(const FragTrap &src): ClapTrap(src._name)
{
	std::cout << "Copy constructor called for [FragTrap]" << src._name << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &src)
{
	std::cout << "Copy assignment operator called for [FragTrap]" << src._name + "_assigned"<< std::endl;
	ClapTrap::operator=(src);
	return (*this);
}

void FragTrap::highFivesGuys(void)
{
    if (this->_health > 0 && this->_energy > 0)
        std::cout << this->_name << " *High five* for guarding the gate like a true hero!" << std::endl;
    else
        std::cout << "Not enough energy or FragTrap is dead." << std::endl;
    return ;
}

