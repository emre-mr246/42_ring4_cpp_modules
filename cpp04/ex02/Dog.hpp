#ifndef DOG_HPP
#define DOG_HPP

#pragma once

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
public:
	Dog(void);
	~Dog();
	Dog(const Dog &src);
	Dog &operator=(const Dog &src);
	void makeSound(void) const;
	void newIdea(unsigned int i, std::string idea);
	const std::string getIdea(unsigned int i) const;

private:
	Brain *_brain;
};

#endif
