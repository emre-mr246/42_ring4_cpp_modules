#include "ICharacter.hpp"

ICharacter::ICharacter(void)
{
    std::cout << "Default constructor called for ICharacter." << std::endl;
}

ICharacter::ICharacter(const ICharacter &src)
{
    *this = src;
    std::cout << "Copy constructor called for ICharacter." << std::endl;
}

ICharacter &ICharacter::operator=(const ICharacter &src)
{
    std::cout << "Copy assignment operator called for ICharacter." << std::endl;
    return (*this);
}
