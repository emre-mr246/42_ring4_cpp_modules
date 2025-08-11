/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 12:37:49 by emgul             #+#    #+#             */
/*   Updated: 2025/07/28 14:27:31 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#pragma once

#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;

class AForm
{
  private:
    const std::string _name;
    bool _isSigned;
    const unsigned int _gradeToSign;
    const unsigned int _gradeToExecute;
    virtual void action() const = 0;

  public:
    AForm(void);
    AForm(const std::string name, unsigned int gradeToSign,
          unsigned int gradeToExecute);
    AForm(const AForm &src);
    virtual ~AForm();
    AForm &operator=(const AForm &src);

    std::string getName() const;
    unsigned int getGradeRequired() const;
    unsigned int getGradeToExecute() const;
    bool getIsSigned() const;
    void setIsSigned(bool isSigned);
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

std::ostream &operator<<(std::ostream &os, AForm const &src);

#endif
