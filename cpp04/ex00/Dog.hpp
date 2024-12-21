#ifndef DOG_HPP
#define DOG_HPP

#pragma once

#include <iostream>
#include "Animal.hpp"

class Dog: public Animal
{
public:
	Dog(void);	
	~Dog();
	Dog(const Dog &src);
	Dog &operator=(const Dog &src);
	void makeSound(void) const;
};

#endif