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
    std::cout << "Copy constructor called for brain." << std::endl;
    *this = src;
    std::cout << "***************" << this->_ideas[1] << std::endl;
}

Brain &Brain::operator=(const Brain &src)
{
    std::cout << "Copy assignment operator called for brain." << std::endl;
    if (this == &src)
        return (*this);
    for (int i = 0; i < 100; i++)
        this->_ideas[i] = src._ideas[i];
    std::cout << "***************" << this->_ideas[1] << std::endl;
    return (*this);
}

void Brain::setIdea(unsigned int i, std::string idea)
{
    if (i <= 100)
        this->_ideas[i] = idea;
    else
        std::cout << "I am just a ANIMAL!!" << std::endl;
}

const std::string Brain::getIdea(unsigned int i) const
{
    if (i <= 100)
    {
        if (this->_ideas[i].size())
            return (this->_ideas[i]);
        else
            return ("There is no idea!");
    }
    else
        return ("I am just a ANIMAL!!");
}
