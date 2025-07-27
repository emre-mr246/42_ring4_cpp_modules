#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#pragma once

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
    std::string _target;
    virtual void action() const;

public:
    RobotomyRequestForm(void);
    RobotomyRequestForm(std::string target);
    ~RobotomyRequestForm();
    RobotomyRequestForm(const RobotomyRequestForm &src);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &src);

    class RobotizationFailed : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
};

#endif
