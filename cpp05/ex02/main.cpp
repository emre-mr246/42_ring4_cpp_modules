/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 12:37:37 by emgul            #+#    #+#              */
/*   Updated: 2025/08/20 14:25:34 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int main()
{
	Bureaucrat emre("Emre", 1);

	std::cout << "==============================================" << std::endl;
	try
	{
		RobotomyRequestForm robotomyForm("RobotomyRequestForm");
		std::cout << robotomyForm << std::endl;
		emre.signForm(robotomyForm);
		emre.executeForm(robotomyForm);
		std::cout << std::endl;

		PresidentialPardonForm pardonForm("PresidentialPardonForm");
		std::cout << pardonForm << std::endl;
		emre.signForm(pardonForm);
		emre.executeForm(pardonForm);
		std::cout << std::endl;

		ShrubberyCreationForm shrubberyForm("ShrubberyCreationForm");
		std::cout << shrubberyForm << std::endl;
		emre.signForm(shrubberyForm);
		emre.executeForm(shrubberyForm);
		std::cout << std::endl;

		RobotomyRequestForm *robotomyForm2 = new RobotomyRequestForm("emre");
		std::cout << *robotomyForm2 << std::endl;
		emre.signForm(*robotomyForm2);
		emre.executeForm(*robotomyForm2);
		delete (robotomyForm2);
	}
	catch (const AForm::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (const AForm::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (const AForm::IsNotSignedException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (const RobotomyRequestForm::RobotizationFailed &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (const PresidentialPardonForm::PresidentialPardonFailed &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (const ShrubberyCreationForm::ShrubberyCreationFailed &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
