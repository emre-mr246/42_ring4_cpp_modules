#include "Cat.hpp"

Cat::Cat(void)
{
    this->_type = "Undefined";
	std::cout << "Default constructor called for [Cat]Default" << std::endl;
}

Cat::Cat(const std::string &type)
{
    this->_type = type;
	std::cout << "Constructor called for [Cat]" << this->_type << std::endl;
}

Cat::~Cat()
{
	std::cout << "Destructor called for [Cat]" << this->_type << std::endl;
}

Cat::Cat(const Cat &src): Animal()
{
	*this = src;
	std::cout << "Copy constructor called for [Cat]" << this->_type << std::endl;
}

Cat &Cat::operator=(const Cat &src)
{
	this->_type = src._type;
	std::cout << "Copy assignment operator called for [Cat]" << this->_type << std::endl;
	return (*this);
}
