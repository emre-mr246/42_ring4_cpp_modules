#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
public:
    Ice();
    ~Ice();
    Ice(const Ice &ref);
    Ice &operator=(const Ice &ref);
    const std::string &getType() const;
    AMateria *clone(void) const;
    void use(ICharacter &src);

private:
    std::string _type;
};

#endif