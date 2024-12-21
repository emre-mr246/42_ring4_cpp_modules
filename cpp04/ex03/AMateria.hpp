#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#pragma once

#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
protected:
    std::string _type;
    AMateria(std::string const & type);

public:
    std::string const & getType() const;
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
};

 #endif