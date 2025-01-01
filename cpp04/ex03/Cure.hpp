#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
public:
    Cure();
    ~Cure();
    Cure(const Cure &ref);
    Cure &operator=(const Cure &ref);
    const std::string &getType() const;
    AMateria *clone(void) const;
    void use(ICharacter &src);
};

#endif