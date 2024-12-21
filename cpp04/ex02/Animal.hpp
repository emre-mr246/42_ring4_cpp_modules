#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#pragma once

#include <iostream>

class Animal
{
public:
	virtual ~Animal();
	Animal(const Animal &src);
	Animal &operator=(const Animal &src);
	virtual void makeSound(void) const = 0;

protected:
	Animal(void);
	std::string _type;
};

#endif