#include "Intern.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

Intern::Intern(void)
{
}

Intern::Intern(const Intern &src)
{
	(void)src;
}

Intern::~Intern()
{
}

Intern &Intern::operator=(const Intern &src)
{
    if (this == &src)
        return (*this);
    return (*this);
}

std::ostream &operator<<(std::ostream &os, Intern const &src)
{
	(void)src;
	return (os);
}

AForm *Intern::makeForm(std::string form, std::string target) const
{
    int i = 0;
    std::string forms[] = {"shrubbery creation", "robotomy request", "presidential pardon"};

    while (i < 3 && form != forms[i])
        i++;
    
    switch (i)
    {
    case 0:
        std::cout << "Intern creates \"ShrubberyCreationForm\" for " << target << "." << std::endl;
        return (new ShrubberyCreationForm(target));
    case 1:
        std::cout << "Intern creates \"RobotomyRequestForm\" for " << target << "." << std::endl;
        return (new RobotomyRequestForm(target));
    case 2:
        std::cout << "Intern creates \"PresidentialPardonForm\" for " << target << "." << std::endl;
        return (new PresidentialPardonForm(target));
    default:
        throw FormNotFoundException();
    }
}

const char *Intern::FormNotFoundException::what() const throw()
{
	return ("Form not found!");
}