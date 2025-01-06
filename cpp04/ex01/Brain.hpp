#ifndef BRAIN_HPP
#define BRAIN_HPP

#pragma once

#include <iostream>

class Brain
{
public:
	Brain(void);
	virtual ~Brain();
	Brain(const Brain &src);
	Brain &operator=(const Brain &src);
	void setIdea(unsigned int i, std::string idea);
	const std::string getIdea(unsigned int i) const;

protected:
	std::string _ideas[100];
};

#endif