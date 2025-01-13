/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:10:16 by emgul             #+#    #+#             */
/*   Updated: 2025/01/13 10:10:18 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
}

Brain &Brain::operator=(const Brain &src)
{
    std::cout << "Copy assignment operator called for brain." << std::endl;
    if (this == &src)
        return (*this);
    for (int i = 0; i < 100; i++)
        if (src._ideas[i].size())
            this->_ideas[i] = src._ideas[i];
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
