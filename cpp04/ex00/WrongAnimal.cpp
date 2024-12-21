#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
    this->_type = "WrongAnimal";
	std::cout << "Default constructor called for " << this->_type << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Destructor called for " << this->_type << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
	*this = src;
	std::cout << "Copy constructor called for " << this->_type << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &src)
{
	this->_type = src._type;
	std::cout << "Copy assignment operator called for " << this->_type << std::endl;
	return (*this);
}

void WrongAnimal::makeSound(void) const
{
	std::cout << this->_type << ": WrongAnimal class's makeSound() function called." << std::endl;
}
