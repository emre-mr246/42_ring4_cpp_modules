/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 12:37:13 by emgul             #+#    #+#             */
/*   Updated: 2025/07/28 12:37:15 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
  private:
    std::string _target;
    virtual void action() const;

  public:
    ShrubberyCreationForm(void);
    ShrubberyCreationForm(std::string target);
    ~ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm &src);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);

    class ShrubberyCreationFailed : public std::exception
    {
      public:
        virtual const char *what() const throw();
    };
};

#endif
