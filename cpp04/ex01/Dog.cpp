#include "Dog.hpp"

Dog::Dog(void)
{
	this->_type = "Dog";
	std::cout << "Default constructor called for " << this->_type << std::endl;
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
	std::cout << "Copy constructor called for " << this->_type << std::endl;
	*this = src;
}

Dog &Dog::operator=(const Dog &src)
{
	std::cout << "TEST COPY ASSIGNMENT" << std::endl;
	std::cout << "Copy assignment operator called for " << this->_type << std::endl;
	this->_type = src._type;
	this->_brain = new Brain(*src._brain);
	return (*this);
}

void Dog::makeSound(void) const
{
	std::cout << this->_type << ": ** Bark! **" << std::endl;
}

void Dog::newIdea(unsigned int i, std::string idea)
{
    this->_brain->setIdea(i, idea);
}

const std::string Dog::getIdea(unsigned int i) const
{
	return (this->_brain->getIdea(i));
}