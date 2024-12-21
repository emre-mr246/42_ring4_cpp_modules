#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#pragma once

#include <iostream>
#include "WrongAnimal.hpp"
#include "Brain.hpp"

class WrongCat : public WrongAnimal
{
public:
	WrongCat(void);
	~WrongCat();
	WrongCat(const WrongCat &src);
	WrongCat &operator=(const WrongCat &src);
	void makeSound(void) const;

private:
	Brain *_brain;
};

#endif