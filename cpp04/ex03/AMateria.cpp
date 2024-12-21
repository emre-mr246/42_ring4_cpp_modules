#include "AMateria.hpp"

AMateria::AMateria(std::string const & type)
{
    std::cout << "Default constructor called for ICharacter." << std::endl;
}

AMateria::~AMateria()
{
    std::cout << "Destructor called for AMateria." << std::endl;
}

AMateria::AMateria(const AMateria &src)
{
    *this = src;
    std::cout << "Copy constructor called for AMateria." << std::endl;
}

AMateria &AMateria::operator=(const AMateria &src)
{
    this->_type = src._type;
    std::cout << "Copy assignment operator called for AMateria." << std::endl;
    return (*this);
}

std::string const & AMateria::getType() const
{
    return (this->_type);
}
