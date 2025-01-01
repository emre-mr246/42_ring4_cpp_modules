#include "Dog.hpp"

Dog::Dog(void)
{
	this->_type = "Dog";
	std::cout << "Default constructor called for " << this->_type << std::endl;
}

Dog::~Dog()
{
	std::cout << "Destructor called for " << this->_type << std::endl;
}

Dog::Dog(const Dog &src) : Animal()
{
	this->_type = src._type;
	std::cout << "Copy constructor called for " << this->_type << std::endl;
}

Dog &Dog::operator=(const Dog &src)
{
	this->_type = src._type;
	std::cout << "Copy assignment operator called for " << this->_type << std::endl;
	return (*this);
}

void Dog::makeSound(void) const
{
	std::cout << this->_type << ": ** Bark! **" << std::endl;
}