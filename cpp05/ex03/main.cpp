/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 12:12:14 by emgul             #+#    #+#             */
/*   Updated: 2025/07/28 15:43:43 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <iostream>

int main()
{
    Bureaucrat emre("Emre", 1);
    Intern intern;

    try
    {
        AForm *form = intern.makeForm("robotomy request", "Emre");
        emre.signForm(*form);
        emre.executeForm(*form);
        delete (form);
    } catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}
