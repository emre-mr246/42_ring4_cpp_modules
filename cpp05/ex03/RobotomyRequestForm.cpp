#include "RobotomyRequestForm.hpp"
#include <stdlib.h>
#include <iostream>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(void): AForm("RobotomyRequestForm", 72, 45), _target("default")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src): AForm(src), _target(src._target)
{
    *this = src;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
    if (this == &src)
        return (*this);
    AForm::operator=(src);
    this->_target = src._target;
    setIsSigned(src.getIsSigned());
    return (*this);
}

void RobotomyRequestForm::action() const
{
    int number;

    srand(time(NULL));
    number = rand() % 2;
    if (number == 0)
    {
        std::cout << "**some drilling noises** " << std::endl;
        std::cout << "Robotomy successful for " << this->_target << "!" << std::endl;
    }
    else
    {
        std::cout << "**some buzzing sounds** " << std::endl;
        throw RobotizationFailed();
    }
}

const char *RobotomyRequestForm::RobotizationFailed::what() const throw()
{
	return ("Robotization failed!");
}