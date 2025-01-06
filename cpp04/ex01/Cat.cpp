#include "Cat.hpp"

Cat::Cat(void)
{
	this->_type = "Cat";
	std::cout << "Default constructor called for " << this->_type << std::endl;
	this->_brain = new Brain();
	if (!this->_brain)
	{
		std::cerr << "Brain allocation failed for Cat!" << std::endl;
		return ;
	}
}

Cat::~Cat()
{
	if (this->_brain)
        delete (this->_brain);
	std::cout << "Destructor called for " << this->_type << std::endl;
}

Cat::Cat(const Cat &src) : Animal()
{
	this->_type = src._type;
	this->_brain = new Brain(*src._brain);
	std::cout << "Copy constructor called for " << this->_type << std::endl;
}

Cat &Cat::operator=(const Cat &src)
{
	this->_type = src._type;
	this->_brain = new Brain(*src._brain);
	std::cout << "Copy assignment operator called for " << this->_type << std::endl;
	return (*this);
}

void Cat::makeSound(void) const
{
	std::cout << this->_type << ": ** Meow! **" << std::endl;
}

void Cat::newIdea(unsigned int i, std::string idea)
{
    this->_brain->setIdea(i, idea);
}