#include "Cat.hpp"

Cat::Cat(void)
{
	this->_type = "Cat";
	this->_brain = new Brain();
	if (!this->_brain)
	{
		std::cerr << "Brain allocation failed for Cat!" << std::endl;
		return ;
	}
	std::cout << "Default constructor called for " << this->_type << std::endl;
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
    if (src._brain)
        this->_brain = new Brain(*src._brain);
	else
        this->_brain = NULL;
    std::cout << "Copy constructor called for " << src._type << std::endl;
}

Cat &Cat::operator=(const Cat &src)
{
    if (this == &src)
    	return (*this);
	this->_type = src._type;
	if (this->_brain)
		delete(this->_brain);
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

const std::string Cat::getIdea(unsigned int i) const
{
	return (this->_brain->getIdea(i));
}