#include "AForm.hpp"
#include <iostream>

AForm::AForm(void): _name("Default Form"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
}

AForm::AForm(std::string name, unsigned int gradeRequired, unsigned int gradeToExecute): _name(name), _isSigned(false), _gradeToSign(gradeRequired), _gradeToExecute(gradeToExecute)
{
	if (gradeRequired < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	else if (gradeRequired > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

AForm::~AForm()
{
}

AForm::AForm(const AForm &src): _name(src._name), _isSigned(src._isSigned), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
{
}

AForm &AForm::operator=(const AForm &src)
{
    if (this == &src)
        return (*this);
    this->_isSigned = src._isSigned;
    return (*this);
}

std::ostream &operator<<(std::ostream &os, AForm const &src)
{
	os << src.getName() << ", form is " << (src.getIsSigned() ? "signed" : "not signed") << ", requires grade " << src.getGradeRequired() << " to sign and grade " << src.getGradeToExecute() << " to execute.";
	return (os);
}

std::string AForm::getName() const
{
    return (this->_name);
}

unsigned int AForm::getGradeRequired() const
{
    return (this->_gradeToSign);
}

unsigned int AForm::getGradeToExecute() const
{
    return (this->_gradeToExecute);
}

bool AForm::getIsSigned() const
{
    return (this->_isSigned);
}

void AForm::setIsSigned(bool isSigned)
{
    this->_isSigned = isSigned;
}

void AForm::beSigned(Bureaucrat const &bureaucrat)
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

void AForm::executeForm(Bureaucrat const &executor) const
{
    if (!this->_isSigned)
    {       
        throw IsNotSignedException();
    }
    if (executor.getGrade() > this->_gradeToExecute)
    {
        throw GradeTooLowException();
    }
    std::cout << executor.getName() << " executes \"" << this->_name << "\"." << std::endl;
    action();
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return ("Grade too high!");
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return ("Grade too low!");
}

const char* AForm::IsNotSignedException::what() const throw()
{
    return ("Form is not signed!");
}