/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 12:38:16 by emgul             #+#    #+#             */
/*   Updated: 2025/07/28 14:25:22 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(void): _name("Mr. Meeseeks"), _grade(150)
{
}

Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const Bureaucrat &src): _name(src._name), _grade(src._grade)
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
    if (this == &src)
        return (*this);
    this->_grade = src._grade;
    return (*this);
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &src)
{
	os << src.getName() << ", bureaucrat grade " << src.getGrade() << ".";
	return (os);
}

std::string Bureaucrat::getName() const
{
	return (this->_name);
}

unsigned int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void Bureaucrat::incrementGrade()
{
	if (this->_grade <= 1)
		throw GradeTooHighException();
	this->_grade--;
	std::cout << "Grade incremented to " << this->_grade << std::endl;
}

void Bureaucrat::decrementGrade()
{
	if (this->_grade >= 150)
		throw GradeTooLowException();
	this->_grade++;
	std::cout << "Grade decremented to " << this->_grade << std::endl;
}

void Bureaucrat::signForm(AForm &form)
{
	if (form.getIsSigned())
    {
        std::cout << this->_name << " cannot sign " << form.getName() << " because it is already signed." << std::endl;
        return;
    }
    if (this->_grade > form.getGradeRequired())
    {
        throw GradeTooLowException();
    }
	std::cout << this->_name << " trying to sign \"" << form.getName() << "\"." << std::endl;
	form.beSigned();
}

void Bureaucrat::executeForm(AForm const &form) const
{
	std::cout << this->_name << " trying to execute " << form.getName() << "." << std::endl;
	form.execute(*this);
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade too high!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade too low!");
}