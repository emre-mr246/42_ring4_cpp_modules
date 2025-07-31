/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 12:38:09 by emgul             #+#    #+#             */
/*   Updated: 2025/07/28 14:22:24 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
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
}

Form::~Form()
{
}

Form::Form(const Form &src): _name(src._name), _isSigned(src._isSigned), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
{
}

Form &Form::operator=(const Form &src)
{
    if (this == &src)
        return (*this);
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

void Form::beSigned()
{
    this->_isSigned = true;
    std::cout << "\"" << this->_name << "\" signed." << std::endl;
}

void Form::execute(Bureaucrat const &executor) const
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
}

const char* Form::GradeTooHighException::what() const throw()
{
    return ("Grade too high!");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ("Grade too low!");
}

const char* Form::IsNotSignedException::what() const throw()
{
    return ("Form is not signed!");
}