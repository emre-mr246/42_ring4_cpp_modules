#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
    std::string _target;
    virtual void action() const;

public:
    PresidentialPardonForm(void);
    PresidentialPardonForm(std::string target);
    ~PresidentialPardonForm();
    PresidentialPardonForm(const PresidentialPardonForm &src);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &src);

    class PresidentialPardonFailed : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
};

#endif
