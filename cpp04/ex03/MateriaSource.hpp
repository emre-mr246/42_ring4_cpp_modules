#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#pragma once

#include <iostream>
#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
private:
	AMateria *_inventory[4];

public:
	MateriaSource(void);
	~MateriaSource();
	MateriaSource(const MateriaSource &src);
	MateriaSource &operator=(const MateriaSource &src);
	void learnMateria(AMateria *materia);
	AMateria* createMateria(std::string const & type);
};

#endif
