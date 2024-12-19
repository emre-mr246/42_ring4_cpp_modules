#include "Animal.hpp"

Animal::Animal(void)
{
	this->_type = "Undefined";
	std::cout << "Default constructor called for [Animal]Default" << std::endl;
}

Animal::Animal(const std::string &type)
{
	this->_type = type;
	std::cout << "Constructor called for [Animal]" << this->_type << std::endl;
}

Animal::~Animal()
{
	std::cout << "Destructor called for [Animal]" << this->_type << std::endl;
}

Animal::Animal(const Animal &src)
{
	*this = src;
	std::cout << "Copy constructor called for [Animal]" << this->_type << std::endl;
}

Animal &Animal::operator=(const Animal &src)
{
	this->_type = src._type;
	std::cout << "Copy assignment operator called for [Animal]" << this->_type << std::endl;
	return (*this);
}

void Animal::makeSound(void) const
{
	std::cout << "The " << this->_type << " made a sound!" << std::endl;
}