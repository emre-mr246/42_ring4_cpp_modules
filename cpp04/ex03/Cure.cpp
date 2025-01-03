#include "Cure.hpp"

Cure::Cure(void)
{
    this->_type = "cure";
    std::cout << "Default constructor called for Cure." << std::endl;
}

Cure::~Cure()
{
    std::cout << "Destructor called for Cure." << std::endl;
}

Cure::Cure(const Cure &src): AMateria(src)
{
    *this = src;
    std::cout << "Copy constructor called for Cure." << std::endl;
}

Cure &Cure::operator=(const Cure &src)
{
    this->_type = src._type;
    std::cout << "Copy assignment operator called for Cure." << std::endl;
    return (*this);
}

void Cure::use(ICharacter &src)
{
    std::cout << "* heals " << src.getName() << "\'s wounds *" << std::endl;
}

AMateria	*Cure::clone(void) const
{
	return (new Cure(*this));
}

std::string const & Cure::getType() const
{
    return (this->_type);
}