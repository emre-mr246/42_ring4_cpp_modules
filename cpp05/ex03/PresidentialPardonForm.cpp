#include "PresidentialPardonForm.hpp"
#include <stdlib.h>
#include <iostream>
#include <ctime>

PresidentialPardonForm::PresidentialPardonForm(void): AForm("PresidentialPardonForm", 25, 5), _target("default")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 25, 5), _target(target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src): AForm(src), _target(src._target)
{
    *this = src;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
    if (this == &src)
        return (*this);
    AForm::operator=(src);
    this->_target = src._target;
    setIsSigned(src.getIsSigned());
    return (*this);
}

void PresidentialPardonForm::action() const
{
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

const char *PresidentialPardonForm::PresidentialPardonFailed::what() const throw()
{
	return ("Presidential pardon failed!");
}