#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#pragma once

#include <iostream>

class WrongAnimal
{
public:
	WrongAnimal(void);
	virtual ~WrongAnimal();
	WrongAnimal(const WrongAnimal &src);
	WrongAnimal &operator=(const WrongAnimal &src);
	void makeSound(void) const;
	
protected:
	std::string _type;
};

#endif