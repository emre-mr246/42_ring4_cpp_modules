#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

Form::Form(void): _name("Default Form"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
	std::cout << "Default constructor called for " << this->_name << std::endl;
}

Form::Form(std::string name, unsigned int gradeRequired, unsigned int gradeToExecute): _name(name), _isSigned(false), _gradeToSign(gradeRequired), _gradeToExecute(gradeToExecute)
{
	if (gradeRequired < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	else if (gradeRequired > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
	this->_gradeToSign = gradeRequired;
	this->_gradeToExecute = gradeToExecute;
	std::cout << "Constructor called for " << this->_name << std::endl;
}

Form::~Form()
{
	std::cout << "Destructor called for " << this->_name << std::endl;
}

Form::Form(const Form &src): _name(src._name), _isSigned(src._isSigned), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
{
    std::cout << "Copy constructor called for " << this->_name << std::endl;
}

Form &Form::operator=(const Form &src)
{
    if (this == &src)
        return (*this);
    this->_name = src._name;
    this->_isSigned = src._isSigned;
    this->_gradeToSign = src._gradeToSign;
    this->_gradeToExecute = src._gradeToExecute;
    std::cout << "Copy assignment operator called for " << this->_name << std::endl;
    return (*this);
}

std::ostream &operator<<(std::ostream &os, Form const &src)
{
	os << src.getName() << ", form is " << (src.getIsSigned() ? "signed" : "not signed") << ", requires grade " << src.getGradeRequired() << " to sign and grade " << src.getGradeToExecute() << " to execute.";
	return (os);
}

std::string Form::getName() const
{
    return (this->_name);
}

unsigned int Form::getGradeRequired() const
{
    return (this->_gradeToSign);
}

unsigned int Form::getGradeToExecute() const
{
    return (this->_gradeToExecute);
}

bool Form::getIsSigned() const
{
    return (this->_isSigned);
}

void Form::beSigned(Bureaucrat const &bureaucrat)
{
    if (this->_isSigned)
    {
        std::cout << bureaucrat.getName() << " cannot sign " << this->_name << " because it is already signed." << std::endl;
        return;
    }
    if (bureaucrat.getGrade() > this->_gradeToSign)
    {
        throw GradeTooLowException();
    }
    this->_isSigned = true;
    std::cout << bureaucrat.getName() << " signs \"" << this->_name << "\"." << std::endl;
}

void Form::executeForm(Bureaucrat const &executor) const
{
    if (!this->_isSigned)
    {
        std::cout << executor.getName() << " cannot execute the form because " << this->_name << " is not signed." << std::endl;
        return;
    }
    if (executor.getGrade() > this->_gradeToExecute)
    {
        throw GradeTooLowException();
    }
    std::cout << executor.getName() << " executes \"" << this->_name << "\"." << std::endl;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return ("Grade too high!");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ("Grade too low!");
}