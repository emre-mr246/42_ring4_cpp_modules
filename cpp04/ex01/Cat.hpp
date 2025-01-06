#ifndef CAT_HPP
#define CAT_HPP

#pragma once

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
public:
	Cat(void);
	~Cat();
	Cat(const Cat &src);
	Cat &operator=(const Cat &src);
	void makeSound(void) const;
	void newIdea(unsigned int i, std::string idea);
	const std::string getIdea(unsigned int i) const;

private:
	Brain *_brain;
};

#endif