/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 12:38:12 by emgul             #+#    #+#             */
/*   Updated: 2025/07/28 14:25:46 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#pragma once

#include "AForm.hpp"
#include <iostream>

class AForm;

class Bureaucrat
{
  private:
    const std::string _name;
    unsigned int _grade;

  public:
    Bureaucrat(void);
    Bureaucrat(const std::string name, int grade);
    ~Bureaucrat();
    Bureaucrat(const Bureaucrat &src);
    Bureaucrat &operator=(const Bureaucrat &src);

    std::string getName() const;
    unsigned int getGrade() const;
    void incrementGrade();
    void decrementGrade();
    void signForm(AForm &form);
    void executeForm(AForm const &form) const;

    class GradeTooLowException : public std::exception
    {
      public:
        virtual const char *what() const throw();
    };
    class GradeTooHighException : public std::exception
    {
      public:
        virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &os, Bureaucrat const &src);

#endif
