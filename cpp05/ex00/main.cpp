/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 12:38:23 by emgul             #+#    #+#             */
/*   Updated: 2025/07/28 12:38:23 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    try
    {
        Bureaucrat emre("Emre", 2);
        Bureaucrat Meeseeks;
        
        std::cout << Meeseeks << std::endl;
        std::cout << emre << std::endl;
        emre.incrementGrade();
        emre.decrementGrade();
        emre.incrementGrade();
        std::cout << emre << std::endl;
        emre.incrementGrade();
    }
    catch (const Bureaucrat::GradeTooHighException &e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}
