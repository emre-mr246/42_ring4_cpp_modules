/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 12:37:20 by emgul             #+#    #+#             */
/*   Updated: 2025/07/28 13:55:30 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#pragma once

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
    std::string _target;
    std::string _name;
    virtual void action() const;

public:
    RobotomyRequestForm(void);
    RobotomyRequestForm(std::string target);
    ~RobotomyRequestForm();
    RobotomyRequestForm(const RobotomyRequestForm &src);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &src);

    class RobotizationFailed : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
};

#endif
