#ifndef FORM_HPP
#define FORM_HPP

#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
private:
    std::string _name;
    bool _isSigned;
    unsigned int _gradeToSign;
    unsigned int _gradeToExecute;

public:
	Form(void);
    Form(const std::string name, unsigned int gradeToSign, unsigned int gradeToExecute);
	~Form();
	Form(const Form &src);
	Form &operator=(const Form &src);

    std::string getName() const;
    unsigned int getGradeRequired() const;
    unsigned int getGradeToExecute() const;
    bool getIsSigned() const;
    void beSigned(Bureaucrat const &bureaucrat);
    void executeForm(Bureaucrat const &executor) const;

    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &os, Form const &src);

#endif
