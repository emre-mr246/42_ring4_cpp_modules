#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int main()
{
    Bureaucrat emre("Emre", 1);

    try
    {
        RobotomyRequestForm form("RobotomyRequestForm");
        std::cout << form << std::endl;
        form.beSigned(emre);
        form.executeForm(emre);

        PresidentialPardonForm pardonForm("PresidentialPardonForm");
        std::cout << pardonForm << std::endl;
        pardonForm.beSigned(emre);
        pardonForm.executeForm(emre);

        ShrubberyCreationForm shrubberyForm("ShrubberyCreationForm");
        std::cout << shrubberyForm << std::endl;
        shrubberyForm.beSigned(emre);
        shrubberyForm.executeForm(emre);
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
