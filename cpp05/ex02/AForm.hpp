#ifndef AFORM_HPP
#define AFORM_HPP

#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class AForm
{
private:
    std::string _name;
    bool _isSigned;
    unsigned int _gradeToSign;
    unsigned int _gradeToExecute;
    virtual void action() const = 0;

public:
	AForm(void);
    AForm(const std::string name, unsigned int gradeToSign, unsigned int gradeToExecute);
	AForm(const AForm &src);
	virtual ~AForm();
	AForm &operator=(const AForm &src);

    std::string getName() const;
    unsigned int getGradeRequired() const;
    unsigned int getGradeToExecute() const;
    bool getIsSigned() const;
    void setIsSigned(bool isSigned);
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
    class IsNotSignedException : public std::exception
    {
    public: 
        virtual const char *what() const throw();
    };

};

std::ostream &operator<<(std::ostream &os, AForm const &src);

#endif
