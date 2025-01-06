#include "Cat.hpp"

Cat::Cat(void)
{
	this->_type = "Cat";
	std::cout << "Default constructor called for " << this->_type << std::endl;
}

Cat::~Cat()
{
	std::cout << "Destructor called for " << this->_type << std::endl;
}

Cat::Cat(const Cat &src) : Animal()
{
	this->_type = src._type;
	std::cout << "Copy constructor called for " << src._type << std::endl;
}

Cat &Cat::operator=(const Cat &src)
{
	if (this == &src)
	{
		return (*this);
	}
	this->_type = src._type;
	std::cout << "Copy assignment operator called for " << this->_type << std::endl;
	return (*this);
}

void Cat::makeSound(void) const
{
	std::cout << this->_type << ": ** Meow! **" << std::endl;
}
