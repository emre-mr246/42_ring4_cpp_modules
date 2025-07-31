/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 12:38:05 by emgul             #+#    #+#             */
/*   Updated: 2025/07/28 14:17:01 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
    const std::string _name;
    bool _isSigned;
    const unsigned int _gradeToSign;
    const unsigned int _gradeToExecute;

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
    void beSigned();
    void execute(Bureaucrat const &executor) const;

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

std::ostream &operator<<(std::ostream &os, Form const &src);

#endif
