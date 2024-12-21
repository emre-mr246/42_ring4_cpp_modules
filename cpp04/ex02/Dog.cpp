#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << "Default constructor called for " << this->_type << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain();
	if (!this->_brain)
	{
		std::cerr << "Brain allocation failed for Dog!" << std::endl;
		return ;
	}
}

Dog::~Dog()
{
	if (this->_brain)
        delete (this->_brain);
	std::cout << "Destructor called for " << this->_type << std::endl;
}

Dog::Dog(const Dog &src) : Animal()
{
	*this = src;
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