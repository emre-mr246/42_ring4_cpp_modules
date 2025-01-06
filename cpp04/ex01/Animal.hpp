#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#pragma once

#include <iostream>

class Animal
{
public:
	Animal(void);
	virtual ~Animal();
	Animal(const Animal &src);
	Animal &operator=(const Animal &src);
	virtual void makeSound(void) const;

protected:
	std::string _type;
};

#endif
