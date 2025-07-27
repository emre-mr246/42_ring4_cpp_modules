#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
    std::string _target;
    virtual void action() const;

public:
    ShrubberyCreationForm(void);
    ShrubberyCreationForm(std::string target);
    ~ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm &src);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);

    class ShrubberyCreationFailed : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
};

#endif
