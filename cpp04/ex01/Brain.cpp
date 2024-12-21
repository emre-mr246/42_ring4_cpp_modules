#include "Brain.hpp"

Brain::Brain(void)
{
    std::cout << "Default constructor called for brain." << std::endl;
}

Brain::~Brain()
{
    std::cout << "Destructor called for brain." << std::endl;
}

Brain::Brain(const Brain &src)
{
    *this = src;
    std::cout << "Copy constructor called for brain." << std::endl;
}

Brain &Brain::operator=(const Brain &src)
{
    std::cout << "Copy assignment operator called for brain." << std::endl;
    if (this == &src)
        return (*this);
    for (int i = 0; i < 100; i++)
        this->_ideas[i] = src._ideas[i];
    return (*this);
}
