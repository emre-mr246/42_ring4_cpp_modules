#include "Ice.hpp"

Ice::Ice(void)
{
    std::cout << "Default constructor called for Ice." << std::endl;
}

Ice::~Ice()
{
    std::cout << "Destructor called for Ice." << std::endl;
}

Ice::Ice(const Ice &src): AMateria()
{
    *this = src;
    std::cout << "Copy constructor called for Ice." << std::endl;
}

Ice &Ice::operator=(const Ice &src)
{
    this->_type = src._type;
    std::cout << "Copy assignment operator called for Ice." << std::endl;
    return (*this);
}

void Ice::use(ICharacter &src)
{
    std::cout << "Ice: * shoots an ice bolt at " << src.getName() << " *" << std::endl;
}

AMateria	*Ice::clone(void) const
{
	return (new Ice(*this));
}