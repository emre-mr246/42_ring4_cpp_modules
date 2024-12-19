#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#pragma once

#include <iostream>

class Animal
{
public:
	Animal(void);	
	Animal(const std::string &type);
	~Animal();
	Animal(const Animal &src);
	Animal &operator=(const Animal &src);
	void makeSound(void) const;

protected:
    std::string _type;
};

#endif