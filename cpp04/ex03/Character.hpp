#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#pragma once

#include <iostream>

class Character
{
public:
	Character(void);
	~Character();
	Character(const Character &src);
	Character &operator=(const Character &src);

protected:
	std::string _name;
};

#endif