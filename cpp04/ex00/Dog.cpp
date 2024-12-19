#include "Dog.hpp"

Dog::Dog(void)
{
    this->_type = "Undefined";
	std::cout << "Default constructor called for [Dog]Default" << std::endl;
}

Dog::Dog(const std::string &type)
{
    this->_type = type;
	std::cout << "Constructor called for [Dog]" << this->_type << std::endl;
}

Dog::~Dog()
{
	std::cout << "Destructor called for [Dog]" << this->_type << std::endl;
}

Dog::Dog(const Dog &src): Animal()
{
	*this = src;
	std::cout << "Copy constructor called for [Dog]" << this->_type << std::endl;
}

Dog &Dog::operator=(const Dog &src)
{
	this->_type = src._type;
	std::cout << "Copy assignment operator called for [Dog]" << this->_type << std::endl;
	return (*this);
}
