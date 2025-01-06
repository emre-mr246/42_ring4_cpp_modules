#ifndef CAT_HPP
#define CAT_HPP

#pragma once

#include <iostream>
#include "Animal.hpp"

class Cat : public Animal
{
public:
	Cat(void);
	~Cat();
	Cat(const Cat &src);
	Cat &operator=(const Cat &src);
	void makeSound(void) const;
};

#endif
