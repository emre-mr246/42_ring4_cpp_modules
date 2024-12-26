#include "AMateria.hpp"

AMateria::AMateria(void)
{
    std::cout << "Default constructor called for ICharacter." << std::endl;
}

AMateria::AMateria(std::string const & type)
{
    this->_type = type;
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

void AMateria::use(ICharacter& target)
{
	std::cout << "AMateria used on " << target.getName() << "." << std::endl;
}
