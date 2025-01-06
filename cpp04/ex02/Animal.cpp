#include "Animal.hpp"

Animal::Animal(void)
{
	this->_type = "Animal";
	std::cout << "Default constructor called for " << this->_type << std::endl;
}

Animal::~Animal()
{
	std::cout << "Destructor called for " << this->_type << std::endl;
}

Animal::Animal(const Animal &src)
{
	*this = src;
	std::cout << "Copy constructor called for " << this->_type << std::endl;
}

Animal &Animal::operator=(const Animal &src)
{
	this->_type = src._type;
	std::cout << "Copy assignment operator called for " << this->_type << std::endl;
	return (*this);
}

void Animal::makeSound(void) const
{
	std::cout << this->_type << ": Animal class's makeSound() function called." << std::endl;
}
