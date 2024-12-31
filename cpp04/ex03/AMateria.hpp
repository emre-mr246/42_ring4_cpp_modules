#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#pragma once

#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
protected:
    std::string _type;

public:
    AMateria(void);
    AMateria(const std::string &type);
    virtual ~AMateria();
    AMateria(const AMateria &src);
    AMateria &operator=(const AMateria &src);
    virtual std::string const &getType() const = 0;
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target) = 0;
};

 #endif
