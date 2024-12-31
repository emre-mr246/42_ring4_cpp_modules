#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#pragma once

#include <iostream>
#include "AMateria.hpp"

class IMateriaSource
{
public:
    virtual ~IMateriaSource() {}
    virtual void learnMateria(AMateria*) = 0;
    virtual AMateria* createMateria(std::string const & type) = 0;
    virtual void materiaList() = 0;
};

#endif