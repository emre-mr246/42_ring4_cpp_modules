/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 12:38:26 by emgul             #+#    #+#             */
/*   Updated: 2025/07/28 12:44:13 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#pragma once

#include <iostream>

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
